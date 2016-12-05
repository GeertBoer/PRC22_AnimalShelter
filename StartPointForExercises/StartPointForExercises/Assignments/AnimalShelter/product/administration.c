#include <stdio.h>
#include <string.h>
#include "administration.h"
#include "resource_detector.h"

int addAnimal(const ANIMAL* animalPtr, ANIMAL* animalArray, int animalArrayLength, int* newAnimalArrayLength)
{
	if (animalPtr == NULL || animalArray ==  NULL || newAnimalArrayLength == NULL)
	{
		return -1;
	}
	animalArray[animalArrayLength - 1] = *animalPtr;
	*newAnimalArrayLength = animalArrayLength + 1;
	return 0;	
}

int removeAnimal(const char* name, ANIMAL* animalArray, int animalArrayLength, int* newAnimalArrayLength)
{
	int numberOfRemovedAnimals = 0;
	if(name == NULL || animalArray == NULL)
	{
		return -1;
	}
	
		for (int i = 0; i < animalArrayLength; ++i)
		{
			if(strcmp(animalArray[i].Name, name) == 0)
			{
				animalArray[i] = animalArray[animalArrayLength -1];
			 	*newAnimalArrayLength = animalArrayLength - 1;
				numberOfRemovedAnimals++;		
			}						
		}
		return numberOfRemovedAnimals;
}

int sortAnimalsByAge(ANIMAL* animalArray, int animalArrayLength)
{
	if (animalArray == NULL)
	{
		return -1;
	}

	ANIMAL tmpAnimal;
	int changed;
	if(animalArray == NULL)
	{
		return -1;
	}	
	do
	{
		changed = 0;
		for (int i = 0; i < animalArrayLength; i++)
		{
			if (animalArray[i].Age < animalArray[i + 1].Age)
			{
				tmpAnimal = animalArray[i];
				animalArray[i] = animalArray[i + 1];
				animalArray[i + 1] = tmpAnimal;
				changed = 1;
			}
		}
	} while (changed == 1);	
	return 0;	
}

int sortAnimalsByYearFound(ANIMAL* animalArray, int animalArrayLength){
    
    ANIMAL tmpAnimal;
    int changed;
    if(animalArray == NULL)
    {
		return -1;
	}
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
	} while (changed==1);  
	return 0;      
}
 
int sortAnimalsBySex(ANIMAL* animalArray, int animalArrayLength){
    
    ANIMAL tmpAnimal;
    int changed;
    int lastIndex;

	if(animalArray == NULL)
	{
		return -1;
	}
	do
	{
		changed = 0;
		for (int i = 0; i < animalArrayLength; i++)
		{
			if(animalArray[i].Sex == Female)
			{               
				tmpAnimal = animalArray[i];
				animalArray[i] = tmpAnimal;
				lastIndex=i;
			}
			else if(animalArray[i].Sex == Male)
			{
				tmpAnimal = animalArray[i]; 
				animalArray[lastIndex+1] = tmpAnimal;                             
			}
			changed = 1;
		}        
	} while (changed == 1);
	return 0;	
}
 
int findAnimalByName(const char* name, const ANIMAL* animalArray, int animalArrayLength, ANIMAL* animalPtr)
{
    if(name == NULL || animalArray == NULL || animalPtr == NULL)
    {
		return -1;      
    }
	for (int i = 0; i < animalArrayLength; i++)
    {
        if(strcmp(animalArray[i].Name, name) == 0)
        {
            *animalPtr = animalArray[i];
            return 0;
        }
    }        	   
	return -1;
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