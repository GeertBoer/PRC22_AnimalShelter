#include <stdio.h>
#include "administration.h"
#include "resource_detector.h"

int addAnimal(const ANIMAL* animalPtr, ANIMAL* animalArray, int animalArrayLength, int* newAnimalArrayLength)
{
	if (animalPtr == NULL || animalArray ==  NULL)
	{
		return -1;
	}
	else 
	{
		animalArray[animalArrayLength - 1] = *animalPtr;
		*newAnimalArrayLength = animalArrayLength + 1;
		return 0;
	}
}