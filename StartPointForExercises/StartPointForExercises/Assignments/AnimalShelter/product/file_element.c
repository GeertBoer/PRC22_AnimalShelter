#include <stdio.h>
#include "file_element.h"
#include "resource_detector.h"
#include "file_element.h"



/* pre    : 
 * post   : If file contains enough Animals, nrAnimals Animals are read into animalPtr.
 *          If less animals than nrAnimals exist, all animals from the file are read into animalPtr.
 * returns: Nr of animals written into animalPtr or -1 if an error occurs
 */
int readAnimals(const char* filename, ANIMAL* animalPtr, int nrAnimals)
{
	char mode = 'r';
	FILE* fp;
	fp = fopen(filename, &mode);

	int animalsInFile = getNrAnimalsInFile(filename);
	int animalsToRead = 0;

	if(filename == NULL || animalPtr == NULL || fp == NULL)
	{
		if (fp == NULL)
		{
			fclose(fp);
		}
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

	fclose(fp);
	return fread(animalPtr, sizeof(ANIMAL), animalsToRead, fp);
}

int writeAnimals(const char* filename, const ANIMAL* animalPtr, int nrAnimals)
{
	FILE* fp;
	char mode = 'w';

	if(filename == NULL || animalPtr == NULL)
	{
		return -1;
	}

	fp = fopen(filename, &mode);
	if(fp != NULL)
	{
		if (fwrite(animalPtr, sizeof(ANIMAL), nrAnimals, fp) != 0)
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
	fp = fopen(filename, &mode);


	if ((filename != NULL) || (fp != NULL))
	{

		fseek(fp, 0L, SEEK_END);  //!!!!!!!!
		int endOfFilePosition = ftell(fp);
		int sizeOfOneAnimal = sizeof(ANIMAL);

		int amountOfAnimals = endOfFilePosition / sizeOfOneAnimal;
		fclose(fp);
		return amountOfAnimals;
	}
	fclose(fp);
	return -1;
}

int readAnimalFromFile(const char* filename, int filePosition, ANIMAL* animalPtr);
/* pre    : 
 * post   : read the animal on filePosition (first animal is filePosition 0,
 *          second animal is filePosition 1, ...) into animalPtr
 * returns: On success: 0
 *          On error: -1 (no data available on filePosition, file could not be read, ...)
 */

int writeAnimalToFile(const char* filename, int filePosition, const ANIMAL* animalPtr);
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

int renameAnimalInFile(const char* filename, int filePosition, const char* animalSurname);
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
}   */