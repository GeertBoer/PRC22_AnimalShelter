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
	TEST_ASSERT_EQUAL(2, newArraySize);
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

//int sortAnimalsByAge(ANIMAL* animalArray, int animalArrayLength)

void test_SortArrayOf3Animals(void)
{
	ANIMAL animal1 = {"Geert", Dog, Male, 19, "Schijndel", {12, 9, 1997}};
	ANIMAL animal2 = {"Mkoen", Dog, Male, 20, "Hamburger", {11, 9, 1938}};
	ANIMAL animal3 = {"Mmroy", Dog, Male, 24, "Limburger", {11, 9, 1838}};
	ANIMAL animalArray[3] = { animal1, animal2, animal3 };

	sortAnimalsByAge(animalArray, 3);

	TEST_ASSERT_EQUAL(24, animalArray[0].Age);
}

void test_SortArrayOfOneAnimal(void)
{
	ANIMAL animal1 = {"Geert", Dog, Male, 19, "Schijndel", {12, 9, 1997}};

	ANIMAL animalArray[1] = { animal1 };

	sortAnimalsByAge(animalArray, 1);

	TEST_ASSERT_EQUAL(19, animalArray[0].Age);
}

int main (int argc, char * argv[])
{
    UnityBegin();

    MY_RUN_TEST(test_addAnimalToArray);
    MY_RUN_TEST(test_addNullAnimalToArray);
    MY_RUN_TEST(test_AddAnimalToNullArray);
    MY_RUN_TEST(test_SortArrayOf3Animals);
    MY_RUN_TEST(test_SortArrayOfOneAnimal);

    return UnityEnd();
}
