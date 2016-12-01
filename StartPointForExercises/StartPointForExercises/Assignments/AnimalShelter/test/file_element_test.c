#include <string.h>

#include "file_element.h"
#include "unity.h"
#include "resource_detector.h"

// I rather dislike keeping line numbers updated, so I made my own macro to ditch the line number
#define MY_RUN_TEST(func) RUN_TEST(func, 0)

const char testFileName[] = "testfile.bin";

void setUp(void)
{
    ANIMAL animal1 = {"Geert", Dog, Male, 19, "Schijndel", {12, 9, 1997}};
	ANIMAL animal2 = {"Mkoen", Dog, Male, 20, "Hamburger", {11, 9, 1938}};
	ANIMAL animal3 = {"Mmroy", Dog, Male, 24, "Limburger", {11, 9, 1838}};
	ANIMAL animalArray[3] = { animal1, animal2, animal3 };

	writeAnimals(testFileName, animalArray, 3);
}

void tearDown(void)
{
    remove(testFileName);
}

void test_EmptyTest(void)
{
    TEST_ASSERT_EQUAL(1, 1);
}

void test_WriteAnimalsTest(void)
{
	ANIMAL animal1 = {"Geert", Dog, Male, 19, "Schijndel", {12, 9, 1997}};
	ANIMAL animal2 = {"Mkoen", Dog, Male, 20, "Hamburger", {11, 9, 1938}};
	ANIMAL animal3 = {"Mmroy", Dog, Male, 24, "Limburger", {11, 9, 1838}};
	ANIMAL animalArray[3] = { animal1, animal2, animal3 };

	TEST_ASSERT_EQUAL(0, writeAnimals("specialTestFile.bin", animalArray, 3));
	remove("specialTestFile.bin");
}

void test_WriteAnimalsNullFilenameTest(void)
{
	ANIMAL animal1 = {"Geert", Dog, Male, 19, "Schijndel", {12, 9, 1997}};
	ANIMAL animal2 = {"Mkoen", Dog, Male, 20, "Hamburger", {11, 9, 1938}};
	ANIMAL animal3 = {"Mmroy", Dog, Male, 24, "Limburger", {11, 9, 1838}};
	ANIMAL animalArray[3] = { animal1, animal2, animal3 };

	TEST_ASSERT_EQUAL(-1, writeAnimals(NULL, animalArray, 3));
}

void test_WriteAnimalsNullArrayTest(void)
{
	TEST_ASSERT_EQUAL(-1, writeAnimals(testFileName, NULL, 3));
}

void test_ReadThreeAnimals(void)
{
	int arraySize = 3;
	ANIMAL animalArray[arraySize];
	int amountOfAnimalsToRead = arraySize;

	int amountOfReadAnimals = readAnimals(testFileName, animalArray, amountOfAnimalsToRead);
	TEST_ASSERT_EQUAL(arraySize, amountOfReadAnimals);
}

void test_ReadAnimalsTooMuchAnimalsToRead(void)
{
	int arraySize = 3;
	ANIMAL animalArray[arraySize];
	int amountOfAnimalsToRead = arraySize + 1;

	int amountOfReadAnimals = readAnimals(testFileName, animalArray, amountOfAnimalsToRead);
	TEST_ASSERT_EQUAL(arraySize, amountOfReadAnimals);
}

void test_ReadAnimalsTooFewAnimalsToRead(void)
{
	int arraySize = 3;
	ANIMAL animalArray[arraySize];
	int amountOfAnimalsToRead = arraySize - 1;

	int amountOfReadAnimals = readAnimals(testFileName, animalArray, amountOfAnimalsToRead);
	TEST_ASSERT_EQUAL(amountOfAnimalsToRead, amountOfReadAnimals);
}

void test_ReadAnimalsNullFilename(void)
{
	int arraySize = 3;
	ANIMAL animalArray[arraySize];
	int amountOfAnimalsToRead = arraySize;

	int amountOfReadAnimals = readAnimals(NULL, animalArray, amountOfAnimalsToRead);
	TEST_ASSERT_EQUAL(-1, amountOfReadAnimals);
}

void test_ReadAnimalsNullArray(void)
{
	int arraySize = 3;
	int amountOfAnimalsToRead = arraySize;

	int amountOfReadAnimals = readAnimals(testFileName, NULL, amountOfAnimalsToRead);
	TEST_ASSERT_EQUAL(-1, amountOfReadAnimals);
}

void test_ReadOneAnimalFromFileWithNullFilename(void)
{
	int arraySize = 3;
	ANIMAL animalArray[arraySize];
	int positionOfReadAnimal = 1;

	int readAnimal = readAnimalFromFile(NULL, positionOfReadAnimal, animalArray);
	TEST_ASSERT_EQUAL(-1, readAnimal);
}

void test_GetNrAnimalsInFile(void)
{
	int amountOfAnimals = getNrAnimalsInFile(testFileName);
	TEST_ASSERT_EQUAL(3, amountOfAnimals);
}

void test_GetNrAnimalsInNULLFile(void)
{
	int amountOfAnimals = getNrAnimalsInFile(NULL);
	TEST_ASSERT_EQUAL(-1, amountOfAnimals);
}

void test_GetNrAnimalsInNotExistingFile(void)
{
	int amountOfAnimals = getNrAnimalsInFile("quooie.mozzls");
	TEST_ASSERT_EQUAL(-1, amountOfAnimals);
}

int main (int argc, char * argv[])
{
    UnityBegin();

    MY_RUN_TEST(test_EmptyTest);
    MY_RUN_TEST(test_WriteAnimalsTest);
    MY_RUN_TEST(test_WriteAnimalsNullFilenameTest);
    MY_RUN_TEST(test_WriteAnimalsNullArrayTest);
    MY_RUN_TEST(test_ReadThreeAnimals);
    MY_RUN_TEST(test_ReadAnimalsTooMuchAnimalsToRead);
    MY_RUN_TEST(test_ReadAnimalsTooFewAnimalsToRead);
    MY_RUN_TEST(test_ReadAnimalsNullFilename);
    MY_RUN_TEST(test_ReadAnimalsNullArray);
    MY_RUN_TEST(test_ReadOneAnimalFromFileWithNullFilename);
    MY_RUN_TEST(test_GetNrAnimalsInFile);
    MY_RUN_TEST(test_GetNrAnimalsInNULLFile);
    MY_RUN_TEST(test_GetNrAnimalsInNotExistingFile);

    remove(testFileName);

    return UnityEnd();
}
