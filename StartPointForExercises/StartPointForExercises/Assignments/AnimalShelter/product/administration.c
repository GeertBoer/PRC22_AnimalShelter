#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "administration.h"
#include "resource_detector.h"

int ageCompareAnimal(const void *voidAnimal1, const void *voidAnimal2)
{
	const ANIMAL *animal1 = (const ANIMAL *)voidAnimal1;
	const ANIMAL *animal2 = (const ANIMAL *)voidAnimal2;

	if (animal1->Age > animal2->Age)
	{
		return 1;
	}
	else if (animal1->Age < animal2->Age)
	{
		return -1;
	}
	else return 0;

}

int yearFoundCompareAnimal(const void *voidAnimal1, const void *voidAnimal2)
{
	const ANIMAL *animal1 = (const ANIMAL *)voidAnimal1;
	const ANIMAL *animal2 = (const ANIMAL *)voidAnimal2;

	if (animal1->DateFound.Year > animal2->DateFound.Year)
	{
		return 1;
	}
	else if (animal1->DateFound.Year < animal2->DateFound.Year)
	{
		return -1;
	}
	else return 0;

}

int stringCompare(const void *voidAnimal1, const void *voidAnimal2)
{
	const ANIMAL *animal1 = (const ANIMAL *)voidAnimal1;
	const ANIMAL *animal2 = (const ANIMAL *)voidAnimal2;

	int comparison = strcmp(animal1->Name, animal2->Name);
	if (comparison > 0)
	{
		return 1;
	}
	else if (comparison < 0)
	{
		return -1;
	}
	return 0;
}

int qsortTest(ANIMAL *animalArray, int animalArrayLength)
{
	qsort(animalArray, animalArrayLength, sizeof(ANIMAL), stringCompare);
	return 0;
}


int addAnimal(const ANIMAL* animalPtr, ANIMAL* animalArray, int animalArrayLength, int* newAnimalArrayLength)
{
	if (animalPtr == NULL || animalArray ==  NULL || newAnimalArrayLength == NULL || animalArrayLength < 0)
	{
		return -1;
	}
	animalArray[animalArrayLength] = *animalPtr;
	*newAnimalArrayLength = animalArrayLength + 1;

	return 0;	
}

int removeAnimal(const char* name, ANIMAL* animalArray, int animalArrayLength, int* newAnimalArrayLength)
{
	if(name == NULL || animalArray == NULL || animalArrayLength < 0 || newAnimalArrayLength == NULL)
	{
		return -1;
	}

	int numberOfRemovedAnimals = 0;
	for (int i = 0; i < animalArrayLength; i++)
	{
		if(strcmp(animalArray[i].Name, name) == 0)
		{
			for (int q = i; q < animalArrayLength; q++)
			{
				animalArray[q] = animalArray[q + 1];
			}
			numberOfRemovedAnimals++;
			i--;
		}						
	}
	
	*newAnimalArrayLength = animalArrayLength - numberOfRemovedAnimals;
	return numberOfRemovedAnimals;
}

int sortAnimalsByAge(ANIMAL* animalArray, int animalArrayLength)
{
	if (animalArray == NULL || animalArrayLength <= 0)
	{
		return -1;
	}

	qsort(animalArray, animalArrayLength, sizeof(ANIMAL), ageCompareAnimal);
	
/*
	ANIMAL tmpAnimal;
	int changed;
	
	do
	{
		changed = 0;
		for (int i = 0; i < animalArrayLength; i++)
		{
			if (animalArray[i + 1].Age < animalArray[i].Age)
			{
				tmpAnimal = animalArray[i];
				animalArray[i] = animalArray[i + 1];
				animalArray[i + 1] = tmpAnimal;
				changed = 1;
			}
		}
	} while (changed == 1);	*/

	return 0;	
}

int sortAnimalsByYearFound(ANIMAL* animalArray, int animalArrayLength)
{

    if(animalArray == NULL || animalArrayLength < 0)
    {
		return -1;
	}
	qsort(animalArray, animalArrayLength, sizeof(ANIMAL), yearFoundCompareAnimal);
/*
    ANIMAL tmpAnimal;
    int changed;
	do
	{
		changed = 0;       
		for (int i = 0; i < animalArrayLength; i++)
		{
			if(animalArray[i].DateFound.Year < animalArray[i + 1].DateFound.Year)
			{
				tmpAnimal = animalArray[i];
				animalArray[i] = animalArray[i + 1];
				animalArray[i + 1] = tmpAnimal;
				changed = 1;
			}
		}
	} while (changed==1);  */

	return 0;      
}
 
int sortAnimalsBySex(ANIMAL* animalArray, int animalArrayLength)
{    
    ANIMAL tmpAnimal;
    int changed;

	if(animalArray == NULL || animalArrayLength < 0)
	{
		return -1;
	}

	do
	{
		changed = 0;
		for (int i = 0; i < animalArrayLength - 1; i++)
		{
			if (animalArray[i].Sex != animalArray[i + 1].Sex)
			{
				if (animalArray[i].Sex == Male)
				{
					tmpAnimal = animalArray[i];
					animalArray[i] = animalArray[i + 1];
					animalArray[i + 1] = tmpAnimal;

					changed = 1;
				}
			}
		}        
	} while (changed == 1);

	return 0;	
}
 
int findAnimalByName(const char* name, const ANIMAL* animalArray, int animalArrayLength, ANIMAL* animalPtr)
{
    if(name == NULL || animalArray == NULL || animalArrayLength < 0 || animalPtr == NULL)
    {
		return -1;
    }

	for (int i = 0; i < animalArrayLength; i++)
    {
        if(strcmp(animalArray[i].Name, name) == 0)
        {
            *animalPtr = animalArray[i];
            return 1;
        }
    }        	   
	return 0;
}

