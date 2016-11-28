#include <string.h>

#include "administration.h"
#include "unity.h"
#include "resource_detector.h"

#include "animal.h"

// I rather dislike keeping line numbers updated, so I made my own macro to ditch the line number
#define MY_RUN_TEST(func) RUN_TEST(func, 0)

void setUp(void)
{
    // This is run before EACH test
}

void tearDown(void)
{
    // This is run after EACH test
}

void test_EmptyTest(void)
{
    TEST_ASSERT_EQUAL(0, 0);
}

//int addAnimal(const ANIMAL* animalPtr, ANIMAL* animalArray, int animalArrayLength, int* newAnimalArrayLength)

void test_addAnimalToArray(void)
{ 
	ANIMAL animal = {"Geert", Dog, Male, 19, "Schijndel", {12, 9, 1997}};
	int arraySize = 1;
	int newArraySize = 0;
	ANIMAL animalArray[arraySize];
	TEST_ASSERT_EQUAL(0 ,addAnimal(&animal, animalArray, arraySize, &newArraySize));
}

void test_addNullAnimalToArray(void)
{
	int arraySize = 1;
	int newArraySize = 0;
	ANIMAL animalArray[arraySize];
	TEST_ASSERT_EQUAL(-1 ,addAnimal(NULL, animalArray, arraySize, &newArraySize));
}

void test_AddAnimalToNullArray(void)
{
	ANIMAL animal = {"Geert", Dog, Male, 19, "Schijndel", {12, 9, 1997}};
	int arraySize = 1;
	int newArraySize = 0;
	TEST_ASSERT_EQUAL(-1 ,addAnimal(&animal, NULL, arraySize, &newArraySize));
}

int main (int argc, char * argv[])
{
    UnityBegin();

    MY_RUN_TEST(test_addAnimalToArray);
    MY_RUN_TEST(test_addNullAnimalToArray);
    MY_RUN_TEST(test_AddAnimalToNullArray);

    return UnityEnd();
}
