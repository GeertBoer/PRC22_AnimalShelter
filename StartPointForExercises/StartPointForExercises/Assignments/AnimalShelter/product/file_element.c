#include <stdio.h>
#include "file_element.h"
#include "resource_detector.h"
#include "file_element.h"

int readAnimals(const char* filename, ANIMAL* animalPtr, int nrAnimals)
{
	FILE* fp;
	char mode = 'r';

	int animalsInFile = getNrAnimalsInFile(filename);
	int animalsReadFromFile = 0;
	
	if(filename == NULL || animalPtr == NULL || (fp = fopen(filename, &mode)) != NULL)
	{
		return -1;
	}

	fp = fopen(filename, &mode);

	if(animalsInFile >= nrAnimals)
	{
		animalsReadFromFile = fread(animalPtr, sizeof(ANIMAL), nrAnimals, fp);	
	}
	else if(animalsInFile < nrAnimals)
	{
		animalsReadFromFile = fread(animalPtr, sizeof(ANIMAL), nrAnimals, fp);
	}
	
	return animalsReadFromFile;
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
	if(fp!=NULL)
	{
		if(fwrite(animalPtr, sizeof(ANIMAL), nrAnimals, fp) == 0)
		{
			return -1;
		}
		else
		{
			fwrite(animalPtr, sizeof(ANIMAL), nrAnimals, fp);
			return 0;
		}		
	}
	else
	{
		return -1;	
	}
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

	if ((filename != NULL) || ((fp = fopen(filename, &mode)) != NULL))
	{
		int endOfFilePosition = fseek(fp, 0, SEEK_END);
		int sizeOfOneAnimal = sizeof(ANIMAL);

		int amountOfAnimals = endOfFilePosition / sizeOfOneAnimal;

		return amountOfAnimals;
	}

	return -1;
}

/* THE FOLLOWING FUNCTIONS ARE REQUIRED FOR THE AnimalRename ASSIGNMENT */
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