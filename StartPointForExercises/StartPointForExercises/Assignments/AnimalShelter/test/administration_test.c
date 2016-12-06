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

void test_AddAnimalToArray(void)
{ 
	ANIMAL animal = {"Geert", Dog, Male, 19, "Schijndel", {12, 9, 1997}};
	int arraySize = 1;
	int newArraySize = 0;
	ANIMAL animalArray[arraySize];
	TEST_ASSERT_EQUAL(0 ,addAnimal(&animal, animalArray, arraySize, &newArraySize));
	TEST_ASSERT_EQUAL(2, newArraySize);
}

void test_AddNullAnimalToArray(void)
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
void test_RemoveAnimalFromEmptyArray(void)
{
	//ANIMAL animal = {"Geert", Dog, Male, 19, "Schijndel", {12, 9, 1997}};
	int arraySize = 0;
	int newArraySize = 0;
	ANIMAL animalArray[arraySize];
	

	int succes = 0;
	succes = removeAnimal("Geert", animalArray, arraySize, &newArraySize);
	TEST_ASSERT_EQUAL(-1, succes);
}

void test_RemoveAnimalWithNULLName(void)
{
	ANIMAL animal = { "Geert", Dog, Male, 19, "Schijndel", {12, 9, 1997} };
	int arraySize = 1;
	int newArraySize = 0;
	ANIMAL animalArray[arraySize];
	addAnimal(&animal, animalArray, arraySize, &newArraySize);

	int succes = 0;
	succes = removeAnimal(NULL, animalArray, arraySize, &newArraySize);
	TEST_ASSERT_EQUAL(-1, succes);
}

void test_RemoveAnimalFromNULLArray(void)
{
	int arraySize = 1;
	int newArraySize = 0;	

	int succes = 0;
	succes = removeAnimal("Geert", NULL, arraySize, &newArraySize);
	TEST_ASSERT_EQUAL(-1, succes);
}

void test_RemoveAnimalSuccess(void)
{
	ANIMAL animal = { "Geert", Dog, Male, 19, "Schijndel", {12, 9, 1997} };
	int arraySize = 1;
	int newArraySize = 0;
	ANIMAL animalArray[arraySize];
	addAnimal(&animal, animalArray, arraySize, &newArraySize);

	int succes = 0;
	succes = removeAnimal("Geert", animalArray, arraySize, &newArraySize);
	TEST_ASSERT_EQUAL(1, succes);
}
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

void test_SortArrayOfAnimalByAgeSucces(void)
{
	ANIMAL animal1 = { "Henkie", Dog, Male, 8, "Carribean", {8,12,1993}};
	ANIMAL animal2 = { "Karel", Cat, Female, 5, "Huukske", {15,9,1997}};
	ANIMAL animal3 = { "Flopke", Dog, Male, 2, "D'n overkant", {16,10,1998}};

	int arraySize = 3;
	ANIMAL animalArray[] = { animal1, animal2, animal3 };

	sortAnimalsByAge(animalArray, arraySize);
	TEST_ASSERT_EQUAL(8, animalArray[0].Age);
	TEST_ASSERT_EQUAL(5, animalArray[1].Age);
	TEST_ASSERT_EQUAL(2, animalArray[2].Age);
	
	TEST_ASSERT_EQUAL(0, sortAnimalsByAge(animalArray, arraySize));
}

void test_SortArrayOfAnimalByAgeArrayIsNull(void)
{
	int arraySize = 3;
	int check = sortAnimalsByAge(NULL, arraySize);

	TEST_ASSERT_EQUAL(-1, check);
}

void test_SortArrayOfAnimalByAgeWhileEmptyArray(void)
{
	int arraySize = 0;
	ANIMAL animalArray[arraySize];

	int check = sortAnimalsByAge(animalArray, arraySize);

	TEST_ASSERT_EQUAL(-1, check);
}

void qsort_testWorking(void)
{
	ANIMAL animal1 = {"b", Dog, Male, 19, "Schijndel", {12, 9, 1997}};
	ANIMAL animal2 = {"a", Dog, Male, 20, "Hamburger", {11, 9, 1938}};
	ANIMAL animal3 = {"c", Dog, Male, 24, "Limburger", {11, 9, 1838}};
	ANIMAL animalArray[3] = { animal1, animal2, animal3 };

	qsortTest(animalArray, 3);
	int comparison = strcmp("a", animalArray[0].Name);

	TEST_ASSERT_EQUAL(0, comparison);
}

int main (int argc, char * argv[])
{
    UnityBegin();

    MY_RUN_TEST(test_AddAnimalToArray);
    MY_RUN_TEST(test_AddNullAnimalToArray);
    MY_RUN_TEST(test_AddAnimalToNullArray);
    MY_RUN_TEST(test_SortArrayOf3Animals);
    MY_RUN_TEST(test_SortArrayOfOneAnimal);
    MY_RUN_TEST(test_RemoveAnimalFromEmptyArray);
    MY_RUN_TEST(test_RemoveAnimalWithNULLName);
    MY_RUN_TEST(test_RemoveAnimalFromNULLArray);
    MY_RUN_TEST(test_RemoveAnimalSuccess);
    MY_RUN_TEST(qsort_testWorking);
    MY_RUN_TEST(test_SortArrayOfAnimalByAgeSucces);
    MY_RUN_TEST(test_SortArrayOfAnimalByAgeArrayIsNull);
    MY_RUN_TEST(test_SortArrayOfAnimalByAgeWhileEmptyArray);
    return UnityEnd();
}
