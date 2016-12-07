#include <stdio.h>
#include <string.h>
#include "file_element.h"
#include "file_element.h"
#include "animal.h"
#include "resource_detector.h"

/* pre    : 
 * post   : If file contains enough Animals, nrAnimals Animals are read into animalPtr.
 *          If less animals than nrAnimals exist, all animals from the file are read into animalPtr.
 * returns: Nr of animals written into animalPtr or -1 if an error occurs
 */
int readAnimals(const char* filename, ANIMAL* animalPtr, int nrAnimals)
{
	if(filename == NULL || strcmp(filename, "") == 0 || animalPtr == NULL || nrAnimals < 0)
	{
		return -1;
	}
	if (nrAnimals == 0)
	{
		return 0;
	}

	char mode = 'r';
	FILE* fp;
	fp = fopen(filename, &mode);

	int animalsInFile = getNrAnimalsInFile(filename);
	int animalsToRead = 0;

	if(fp == NULL)
	{
		return -1;
	}

	if (animalsInFile >= nrAnimals)
	{
		animalsToRead = nrAnimals;
	}
	else
	{
		animalsToRead = animalsInFile;
	}
	int succes = fread(animalPtr, sizeof(ANIMAL), animalsToRead, fp);

	fclose(fp);
	return succes;
}



int writeAnimals(const char* filename, const ANIMAL* animalPtr, int nrAnimals)
{
	FILE* fp;
	char mode = 'w';

	if(filename == NULL /* || strcmp(filename, "") == 0 || animalPtr == NULL || nrAnimals < 0*/)
	{
		printf("%s\n", "een");
		return -1;
	}
	if (strcmp(filename, "") == 0)
	{
		printf("%s\n", "twee");
		return -1;
	}
	if (animalPtr == NULL)
	{
		printf("%s\n", "drie");
		return -1;
	}
	if (nrAnimals < 0)
	{
		printf("%s\n", "vier");
		return -1;
	}

	fp = fopen(filename, &mode);
	if(fp != NULL)
	{
		if(fwrite(animalPtr, sizeof(ANIMAL), nrAnimals, fp) != 0)
		{
			fclose(fp);
			return 0;
		}		
	}

	fclose(fp);
	return -1;	
}
/* pre    : 
 * post   : nrAnimals animals are written into a new file with data from animalPtr
 * returns: On succes: 0
 *          In case of an error (file could not be written, input pointers are NULL): -1
 */


int getNrAnimalsInFile(const char* filename)
{
	char mode = 'r';
	FILE* fp; 
	if(filename == NULL || strcmp(filename, "") == 0)
	{
		return -1;
	}

	fp = fopen(filename, &mode);
	if (fp != NULL)
	{	
		fseek(fp, 0L, SEEK_END);  //!!!!!!!!
		int endOfFilePosition = ftell(fp);
		int sizeOfOneAnimal = sizeof(ANIMAL);

		int amountOfAnimals = endOfFilePosition / sizeOfOneAnimal;
		fclose(fp);
		return amountOfAnimals;
	}

	return -1;
}

/* THE FOLLOWING FUNCTIONS ARE REQUIRED FOR THE AnimalRename ASSIGNMENT */
int readAnimalFromFile(const char* filename, int filePosition, ANIMAL* animalPtr)
{
	if (filename == NULL || strcmp(filename, "") == 0 || filePosition < 0|| animalPtr == NULL)
	{		
		return -1;
	}

	char mode = 'r';
	FILE* fp;

	int animalPosition = filePosition * sizeof(ANIMAL);
		
	fp = fopen(filename, &mode);
	

	if(fp != NULL)
	{
		fseek(fp, 0l, SEEK_END);
		int endOfFile = ftell(fp);
		if(endOfFile <= animalPosition)
		{			
			fclose(fp);
			return -1;
		}

		fseek(fp, 0, SEEK_SET);			//////AANGEPAST
		fseek(fp, animalPosition, 0);						
		if(fread(animalPtr, sizeof(ANIMAL), 1, fp) == 1)
		{	
			fclose(fp);
			return 0;
		}		

		fclose(fp);
		return -1;	
	}
	return -1;
}
/* pre    : 
 * post   : read the animal on filePosition (first animal is filePosition 0,
 *          second animal is filePosition 1, ...) into animalPtr
 * returns: On success: 0
 *          On error: -1 (no data available on filePosition, file could not be read, ...)
 */

int writeAnimalToFile(const char* filename, int filePosition, const ANIMAL* animalPtr)
{
	if(filename == NULL || strcmp(filename, "") == 0 || filePosition < 0 || animalPtr == NULL)
	{
		return - 1;
	}

	ANIMAL a = *animalPtr;
	char animalName[30];
	strcpy(animalName, a.Name);

	FILE *fp;
	char filemode[] = "r+";
	fp = fopen(filename, filemode);

	if (fp == NULL)
	{
		char writemode = 'w';
		fp = fopen(filename, &writemode);
		if (fp == NULL)
		{
			return -1;
		}
	}

	int positionToWrite = filePosition * sizeof(ANIMAL);
	//fseek(fp, SEEK_SET, positionToWrite);
	fseek(fp, 0, SEEK_SET);
	fseek(fp, positionToWrite, 0);
	fwrite(animalPtr, sizeof(ANIMAL), 1, fp);

	fclose(fp);
	return 0;
}
/* pre    : 
 * post   : write the animal in animalPtr to the file at position 'filePosition'
 * returns: On success: 0
 *          On error: -1
 *
 **** note: do not open the file in append mode (a or a+): in append mode you ALWAYS
 ****       write to the end of the file. You cannot open the file in write mode either
 ****       (w or w+), as this will truncate an existing file to 0 bytes.
 ****       You MUST open the file in "r+" mode (means: r+w) and if that fails
 ****       (could mean: file does not exist) retry in "w" mode.
 */

int renameAnimalInFile(const char* filename, int filePosition, const char* animalSurname)
{
	ANIMAL animalToRename;
	char tmpName[60];
	const int maxAnimalNameSize = 25;

	if ((readAnimalFromFile(filename, filePosition, &animalToRename) == -1) || (animalSurname == NULL) || (strlen(animalSurname) <= 0))
	{
		return -1;
	}

	int currentNameSize = strlen(animalToRename.Name);
	int animalSurnameSize = strlen(animalSurname);
	int sizeOfOneSpace = sizeof(char);
	int sizeOfNullTerminator = sizeof(char);

	if (!strlen(animalSurname))
	{
		return -1;
	}
	if (animalSurnameSize > maxAnimalNameSize)
	{
		return -1;
	}
	if ((currentNameSize + animalSurnameSize + sizeOfNullTerminator + sizeOfOneSpace) > maxAnimalNameSize)
	{
		return -1;
	}

	strcpy(tmpName, animalSurname);
	strcat(tmpName, " ");
	strcat(tmpName, animalToRename.Name);
	strcpy(animalToRename.Name, tmpName);

	if (writeAnimalToFile(filename, filePosition, &animalToRename) == -1)
	{
		return -1;
	}

	return 0;
}
/* pre	   :
 * post    : change the name of the animal on the filePosition in this way:
 *	     The new name of the animal will start with the animalSurname, followed by a space and followed by the original animal name
 *	     Example : We have animal called "Max" on the filePosition and animalSurname "Verstappen". The new name of the animal will be "Verstappen Max".
 *	     The renamed animal will be written back to the file.
 *  returns: On success: 0
 *           On error: -1
 */


/*	####################################### Waar worden files eigenlijk opgeslagen
void testFileIO()
{
	char filename[] = "file.bin";
	char filemode = 'w';
	FILE *fp = fopen(filename, &filemode);
	fseek(fp, 0, SEEK_END);
	fclose(fp);
}   ###GEVONDEN#### */