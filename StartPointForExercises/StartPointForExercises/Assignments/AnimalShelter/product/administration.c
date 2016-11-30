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

int sortAnimalsByAge(ANIMAL* animalArray, int animalArrayLength)
{
	ANIMAL tmpAnimal;
	int changed;
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
/* pre    : 
 * post   : All animals in animalArray are sorted by age
 * returns: 0 on success or -1 if an error occurs
 */

int sortAnimalsByYearFound(ANIMAL* animalArray, int animalArrayLength){
    
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
    } while (changed==1);
    
    return 0;
        
}
 
int sortAnimalsBySex(ANIMAL *animalArray, int animalArrayLength){
    
    ANIMAL tmpAnimal;
    int changed;
    int lastIndex;

    do
    {
        changed = 0;

        for (int i = 0; i < animalArrayLength; i++)
        {
            if(animalArray[i].Sex == Female){               
                tmpAnimal = animalArray[i];
                animalArray[i] = tmpAnimal;
                lastIndex=i;
            }
            else if(animalArray[i].Sex == Male){
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
    if(name != NULL){
        for (int i = 0; i < animalArrayLength; i++)
        {
            if(animalArray[i].Name == name){
                *animalPtr = animalArray[i];
                return 0;
            }
        }
    }
    return -1;
}
