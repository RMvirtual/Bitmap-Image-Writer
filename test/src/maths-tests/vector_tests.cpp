#include <gtest/gtest.h>
#include <iostream>
#include "src/maths/vector/vector.h"

using namespace Vectorable;

TEST(VectorTests, ShouldCreateVectorWithOneAndTwo)
{
    Vector vector = Vector(1, 2);
    EXPECT_EQ(1, vector.get(0));
    EXPECT_EQ(2, vector.get(1));
}

TEST(VectorTests, ShouldCreateVectorWithFourFiveAndSix)
{
    Vector vector = Vector(4, 5, 6);
    EXPECT_EQ(4, vector.get(0));
    EXPECT_EQ(5, vector.get(1));
    EXPECT_EQ(6, vector.get(2));

    // std::cout << "\n6: " + std::to_string(6);
    // std::cout << "\nV: " + std::to_string(vector.get(2));
}

TEST(VectorTests, ShouldCreateVectorWithOneTwoThreeAndFour)
{
    Vector vector = Vector(1, 2, 3, 4);
    EXPECT_EQ(1, vector.get(0));
    EXPECT_EQ(2, vector.get(1));
    EXPECT_EQ(3, vector.get(2));
    EXPECT_EQ(4, vector.get(3));
}

TEST(VectorTests, ShouldCreateVectorWithArray)
{
    double array[] = {1, 2, 3};
    Vector vector = Vector(array, 3);

    EXPECT_EQ(1, vector.get(0));
    EXPECT_EQ(2, vector.get(1));
    EXPECT_EQ(3, vector.get(2));
}

TEST(VectorTests, LengthShouldBeTwo)
{
    Vector vector = Vector(1, 2);
    EXPECT_EQ(2, vector.length());
}

TEST(VectorTests, LengthShouldBeFive)
{
    double array[] {1, 2, 3, 4, 5};
    Vector vector = Vector(array, 5);
    EXPECT_EQ(5, vector.length());
}

TEST(VectorTests, ShouldCalculateMagnitudeWithTwoElements)
{
    Vector vectorWithMagnitudeOf13 = Vector(12, -5);
    double magnitude = vectorWithMagnitudeOf13.magnitude();

    EXPECT_DOUBLE_EQ(13, magnitude);

    Vector vectorWithMagnitudeOfSqrt5 = Vector(1, -2);
    magnitude = vectorWithMagnitudeOfSqrt5.magnitude();

    EXPECT_DOUBLE_EQ(sqrt(5), magnitude);
}

TEST(VectorTests, ShouldIndexDirectlyWithOperator)
{
    Vector vector = Vector(5, 6);

    EXPECT_DOUBLE_EQ(5, vector[0]);
    EXPECT_DOUBLE_EQ(6, vector[1]);
}

TEST(VectorTests, ShouldAddTwoVectorsWithPositiveValues)
{
    Vector lhsVector = Vector(1, 2, 3, 4);
    Vector rhsVector = Vector(5, 6, 7, 8);

    Vector newVector = lhsVector + rhsVector;

    double correctValues[] = {6, 8, 10, 12};

    for (int elementNo = 0; elementNo < newVector.length(); elementNo++)
        EXPECT_DOUBLE_EQ(correctValues[elementNo], newVector[elementNo]);
}

TEST(VectorTests, ShouldAddTwoVectorsWithMixedValues)
{
    Vector lhsVector = Vector(-1, -5, 15, 6);
    Vector rhsVector = Vector(5, 6, -7, 8);
    Vector newVector = lhsVector + rhsVector;

    double correctValues[] = {4, 1, 8, 14};

    for (int elementNo = 0; elementNo < newVector.length(); elementNo++)
        EXPECT_DOUBLE_EQ(correctValues[elementNo], newVector[elementNo]);
}

TEST(VectorTests, ShouldSubtractTwoVectorsWithPositiveValues)
{
    Vector lhsVector = Vector(5, 6, 7, 8);
    Vector rhsVector = Vector(1, 3, 5, 7);

    Vector newVector = lhsVector - rhsVector;

    double correctValues[] = {4, 3, 2, 1};

    for (int elementNo = 0; elementNo < newVector.length(); elementNo++)
        EXPECT_DOUBLE_EQ(correctValues[elementNo], newVector[elementNo]);
}

TEST(VectorTests, ShouldSubtractTwoVectorsWithMixedValues)
{
    Vector lhsVector = Vector(-1, -5, 15, 6);
    Vector rhsVector = Vector(5, 6, -7, 8);
    Vector newVector = lhsVector - rhsVector;

    double correctValues[] = {-6, -11, 22, -2};

    for (int elementNo = 0; elementNo < newVector.length(); elementNo++)
        EXPECT_DOUBLE_EQ(correctValues[elementNo], newVector[elementNo]);
}