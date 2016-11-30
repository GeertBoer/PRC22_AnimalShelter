#include <stdio.h>
#include "file_element.h"
#include "resource_detector.h"

int readAnimals(const char* filename, ANIMAL* animalPtr, int nrAnimals)
{
	//unsigned char buffer[1000];
	FILE* fp;
	int animalsInFile = 0;
	char mode = 'r';
	if(filename == NULL || animalPtr == NULL)
	{
		return -1;
	}
	fp = fopen(filename, &mode);
	if(nrAnimals == getNrAnimalsInFile)
	{
		animalsInFile = fread(animalPtr, sizeof(ANIMAL), nrAnimals, fp);	
	}
	else if(getNrAnimalsInFile < nrAnimals)
	{
		animalsInFile = fread(animalPtr, sizeof(ANIMAL), nrAnimals, fp);
	}
	else
	{
		return -1;
	}
	return animalsInFile;


}

// int writeAnimals(const char* filename, const ANIMAL* animalPtr, int nrAnimals)
// {

// }

// int getNrAnimalsInFile(const char* filename)
// {
// 	//int animalsInFile;
// 	unsigned char buffer[1000];
// 	FILE* ptr;
// 	if(filename == NULL || *filename == "")
// 	{
// 		return -1;
// 	}
// 	ptr = fopen(filename, rb);
// 	fread(buffer, sizeof(buffer), , ptr);
// 	animalsInFile = sizeof(buffer) / sizeof(ANIMAL);

	
	
// }

// int readAnimalFromFile(const char* filename, int filePosition, ANIMAL* animalPtr)
// {

// }

// int writeAnimalToFile(const char* filename, int filePosition, const ANIMAL* animalPtr)
// {

// }

// int renameAnimalInFile(const char* filename, int filePosition, const char* animalSurname)
// {

// }