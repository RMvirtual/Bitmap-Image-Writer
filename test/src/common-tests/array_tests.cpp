#include <gtest/gtest.h>
#include <iostream>
#include "src/common/arrays.h"

TEST(ArrayTests, ShouldAddSingleElement)
{
  ArrayList<int> arrayList;
  int correctNumber = 5;

  arrayList.add(correctNumber);
  int number = arrayList.get(0);

  EXPECT_EQ(number, correctNumber);
}

TEST(ArrayTests, ShouldAddFiveElements)
{
  ArrayList<int> arrayList;

  for (int i = 0; i < 5; i++)
  {
    int numberToAdd = i + 5;
    arrayList.add(numberToAdd);
  }

  int correctNumbers[] = {5, 6, 7, 8, 9};

  for (int i = 0; i < 5; i++)
  {
    int number = arrayList.get(i);
    int correctNumber = correctNumbers[i];

    EXPECT_EQ(number, correctNumber);
  }
}

TEST(ArrayTests, ShouldReturnLengthOfFive)
{
  ArrayList<double> arrayList;
  int correctSize = 5;

  for (int i = 0; i < correctSize; i++)
  {
    double numberToAdd = i + 1;
    arrayList.add(numberToAdd);
  }

  int actualSize = arrayList.size();
  EXPECT_EQ(actualSize, correctSize);
}

TEST(ArrayTests, ShouldGet3rdElement)
{
  ArrayList<int> arrayList;

  for (int i = 0; i < 5; i++)
  {
    int numberToAdd = i + 5;
    arrayList.add(numberToAdd);
  }

  int number = arrayList.get(2);
  int correctNumber = 7;

  EXPECT_EQ(number, correctNumber);
}

TEST(ArrayTests, ShouldRemove3rdElement)
{
  ArrayList<int> arrayList;

  for (int i = 0; i < 5; i++)
  {
    int numberToAdd = i + 5;
    arrayList.add(numberToAdd);
  }

  arrayList.remove(2);
  int thirdElement = arrayList.get(2);
  int correctNumber = 8;

  EXPECT_EQ(thirdElement, correctNumber);
}

TEST(ArrayTests, ShouldInsertElementAt3rdIndex)
{
  ArrayList<int> arrayList;
  int correctNumber = 10;

  for (int i = 0; i < 5; i++)
  {
    int numberToAdd = i + 5;
    arrayList.add(numberToAdd);
  }

  arrayList.insert(2, correctNumber);
  int number = arrayList.get(2);

  EXPECT_EQ(number, correctNumber);
}

TEST(ArrayTests, ShouldSetElementAt4thIndex)
{
  ArrayList<int> arrayList;
  int correctNumber = 200;

  for (int i = 0; i < 5; i++)
  {
    int numberToAdd = i + 10;
    arrayList.add(numberToAdd);
  }

  arrayList.set(3, correctNumber);
  int number = arrayList.get(3);

  EXPECT_EQ(number, correctNumber);
}

TEST(ArrayTests, ShouldCalculateSizeAfterRemove)
{
  ArrayList<int> arrayList;

  int startingSize = 5;

  for (int i = 0; i < startingSize; i++)
  {
    int numberToAdd = i + 5;
    arrayList.add(numberToAdd);
  }

  arrayList.remove(2);

  int sizeAfterRemove = arrayList.size();
  int correctSizeAfterRemove = startingSize - 1;

  EXPECT_EQ(sizeAfterRemove, correctSizeAfterRemove);
}

TEST(ArrayTests, ShouldCalculateSizeAfterAddition)
{
  ArrayList<int> arrayList;

  int startingSize = 5;

  for (int i = 0; i < startingSize; i++)
  {
    int numberToAdd = i + 5;
    arrayList.add(numberToAdd);
  }

  arrayList.add(361);

  int sizeAfterAddition = arrayList.size();
  int correctSizeAfterAddition = startingSize + 1;

  EXPECT_EQ(sizeAfterAddition, correctSizeAfterAddition);
}

TEST(ArrayTests, ShouldCalculateSizeAfterInsert)
{
  ArrayList<int> arrayList;

  int startingSize = 5;

  for (int i = 0; i < startingSize; i++)
  {
    int numberToAdd = i + 5;
    arrayList.add(numberToAdd);
  }

  arrayList.insert(2, 361);

  int sizeAfterInsert = arrayList.size();
  int correctSizeAfterInsert = startingSize + 1;

  EXPECT_EQ(sizeAfterInsert, correctSizeAfterInsert);
}

TEST(ArrayTests, ShouldCalculateSizeAfterSet)
{
  ArrayList<int> arrayList;

  int startingSize = 5;

  for (int i = 0; i < startingSize; i++)
  {
    int numberToAdd = i + 5;
    arrayList.add(numberToAdd);
  }

  arrayList.set(2, 361);
  int sizeAfterInsert = arrayList.size();

  EXPECT_EQ(sizeAfterInsert, startingSize);
}