#include <gtest/gtest.h>
#include <iostream>
#include "src/maths/vector/vector.h"

using namespace Vectorable;

TEST(VectorTests, ShouldCreateVectorWith1And2)
{
    Vector vector = Vector(1, 2);
    EXPECT_EQ(1, vector.get(0));
    EXPECT_EQ(2, vector.get(1));
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
    int length = vector.length();

    EXPECT_EQ(2, length);
}

TEST(VectorTests, LengthShouldBeFive)
{
    double array[] {1, 2, 3, 4, 5};
    Vector vector = Vector(array, 5);
    EXPECT_EQ(5, vector.length());
}

TEST(VectorTests, ShouldCalculateMagnitude)
{
    Vector vectorWithMagnitudeOf13 = Vector(12, -5);
    double magnitude = vectorWithMagnitudeOf13.magnitude();

    EXPECT_DOUBLE_EQ(magnitude, 13);

    Vector vectorWithMagnitudeOfSqrt5 = Vector(1, -2);
    magnitude = vectorWithMagnitudeOfSqrt5.magnitude();

    EXPECT_DOUBLE_EQ(magnitude, sqrt(5));
}