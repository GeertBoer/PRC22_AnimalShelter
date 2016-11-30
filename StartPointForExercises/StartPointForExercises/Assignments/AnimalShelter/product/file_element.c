#include <stdio.h>
#include "file_element.h"
#include "resource_detector.h"

int readAnimals(const char* filename, ANIMAL* animalPtr, int nrAnimals)
{
	if(filename == NULL || *filename == "" || animalPtr == NULL)
	{
		return -1;
	}
	int animalsInFile;

}

int writeAnimals(const char* filename, const ANIMAL* animalPtr, int nrAnimals)
{

}

int getNrAnimalsInFile(const char* filename)
{
	int animalsInFile;
	if(filename == NULL || *filename == "")
	{
		return -1;
	}
	fopen(filename, r);
	
	
}

int readAnimalFromFile(const char* filename, int filePosition, ANIMAL* animalPtr)
{

}

int writeAnimalToFile(const char* filename, int filePosition, const ANIMAL* animalPtr)
{

}

int renameAnimalInFile(const char* filename, int filePosition, const char* animalSurname)
{

}