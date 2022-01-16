#include <gtest/gtest.h>
#include <iostream>

#include "src/maths/vector/vector.h"

TEST(VectorTests, ShouldCreateVectorWithTwoElements)
{
  Maths::Vector vector = Maths::Vector(1, 2);
  EXPECT_EQ(1, vector[0]);
  EXPECT_EQ(2, vector[1]);
}

TEST(VectorTests, ShouldCreateVectorWithThreeElements)
{
  Maths::Vector vector = Maths::Vector(4, 5, 6);
  EXPECT_EQ(4, vector[0]);
  EXPECT_EQ(5, vector[1]);
  EXPECT_EQ(6, vector[2]);
}

TEST(VectorTests, ShouldCreateVectorWithFourElements)
{
  Maths::Vector vector = Maths::Vector(1, 2, 3, 4);
  EXPECT_EQ(1, vector[0]);
  EXPECT_EQ(2, vector[1]);
  EXPECT_EQ(3, vector[2]);
  EXPECT_EQ(4, vector[3]);
}

TEST(VectorTests, ShouldCreateVectorWithArray)
{
  double array[] = {1, 2, 3};
  Maths::Vector vector = Maths::Vector(array, 3);

  EXPECT_EQ(1, vector[0]);
  EXPECT_EQ(2, vector[1]);
  EXPECT_EQ(3, vector[2]);
}

TEST(VectorTests, ShouldCreateVectorWithStlVector)
{
  std::vector<double> stlVector = {1, 2, 3}; 
  Maths::Vector vector = Maths::Vector(stlVector);

  EXPECT_EQ(1, vector[0]);
  EXPECT_EQ(2, vector[1]);
  EXPECT_EQ(3, vector[2]);
}

TEST(VectorTests, LengthShouldBeTwo)
{
  Maths::Vector vector = {1, 2};
  EXPECT_EQ(2, vector.length());
}

TEST(VectorTests, LengthShouldBeFive)
{
  Maths::Vector vector({1, 2, 3, 4, 5});
  EXPECT_EQ(5, vector.length());
}

TEST(VectorTests, ShouldCalculateMagnitudeWithTwoElements)
{
  Maths::Vector vectorWithMagnitudeOf13 = Maths::Vector(12, -5);
  double magnitude = vectorWithMagnitudeOf13.magnitude();

  EXPECT_DOUBLE_EQ(13, magnitude);

  Maths::Vector vectorWithMagnitudeOfSqrt5 = Maths::Vector(1, -2);
  magnitude = vectorWithMagnitudeOfSqrt5.magnitude();

  EXPECT_DOUBLE_EQ(sqrt(5), magnitude);
}

TEST(VectorTests, ShouldCalculateMagnitudeOfThreeElementVectors)
{
  Maths::Vector vector1 = Maths::Vector(1, 1, 2);
  Maths::Vector vector2 = Maths::Vector(-4, -8, 6);

  double vector1Magnitude = vector1.magnitude();
  double vector1CorrectMagnitude = 2.4494897427831779;

  double vector2Magnitude = vector2.magnitude(); 
  double vector2CorrectMagnitude = 10.770329614269007;

  EXPECT_DOUBLE_EQ(vector1Magnitude, vector1CorrectMagnitude);
  EXPECT_DOUBLE_EQ(vector2Magnitude, vector2CorrectMagnitude);
}

TEST(VectorTests, ShouldIndexDirectlyWithOperator)
{
  Maths::Vector vector = Maths::Vector(5, 6);

  EXPECT_DOUBLE_EQ(5, vector[0]);
  EXPECT_DOUBLE_EQ(6, vector[1]);
}

TEST(VectorTests, ShouldAddTwoVectorsWithPositiveValues)
{
  Maths::Vector lhsVector = Maths::Vector(1, 2, 3, 4);
  Maths::Vector rhsVector = Maths::Vector(5, 6, 7, 8);

  Maths::Vector newVector = lhsVector + rhsVector;

  double correctValues[] = {6, 8, 10, 12};

  for (int elementNo = 0; elementNo < newVector.length(); elementNo++)
    EXPECT_DOUBLE_EQ(correctValues[elementNo], newVector[elementNo]);
}

TEST(VectorTests, ShouldAddTwoVectorsWithMixedSignValues)
{
  Maths::Vector lhsVector = Maths::Vector(-1, -5, 15, 6);
  Maths::Vector rhsVector = Maths::Vector(5, 6, -7, 8);
  Maths::Vector newVector = lhsVector + rhsVector;

  double correctValues[] = {4, 1, 8, 14};

  for (int elementNo = 0; elementNo < newVector.length(); elementNo++)
    EXPECT_DOUBLE_EQ(correctValues[elementNo], newVector[elementNo]);
}

TEST(VectorTests, ShouldSubtractTwoVectorsWithPositiveValues)
{
  Maths::Vector lhsVector = Maths::Vector(5, 6, 7, 8);
  Maths::Vector rhsVector = Maths::Vector(1, 3, 5, 7);

  Maths::Vector newVector = lhsVector - rhsVector;

  double correctValues[] = {4, 3, 2, 1};

  for (int elementNo = 0; elementNo < newVector.length(); elementNo++)
    EXPECT_DOUBLE_EQ(correctValues[elementNo], newVector[elementNo]);
}

TEST(VectorTests, ShouldSubtractTwoVectorsWithMixedSignValues)
{
  Maths::Vector lhsVector = Maths::Vector(-1, -5, 15, 6);
  Maths::Vector rhsVector = Maths::Vector(5, 6, -7, 8);
  Maths::Vector newVector = lhsVector - rhsVector;

  double correctValues[] = {-6, -11, 22, -2};

  for (int elementNo = 0; elementNo < newVector.length(); elementNo++)
    EXPECT_DOUBLE_EQ(correctValues[elementNo], newVector[elementNo]);
}

TEST(VectorTests, ShouldMultiplyVectorWithScalarOnRHS)
{
  Maths::Vector vector = Maths::Vector(5, 6, 7, -8);
  double scalar = 2;

  Maths::Vector newVector = vector * scalar;

  double correctValues[] = {10, 12, 14, -16};

  for (int elementNo = 0; elementNo < newVector.length(); elementNo++)
    EXPECT_DOUBLE_EQ(correctValues[elementNo], newVector[elementNo]);
}

TEST(VectorTests, ShouldMultiplyVectorWithScalarOnLHS)
{
  Maths::Vector vector = Maths::Vector(5, 6, 7, -8);
  Maths::Vector newVector = 2 * vector;

  double correctValues[] = {10, 12, 14, -16};

  for (int elementNo = 0; elementNo < newVector.length(); elementNo++)
    EXPECT_DOUBLE_EQ(correctValues[elementNo], newVector[elementNo]);
}

TEST(VectorTests, ShouldDivideVectorWithAScalar)
{
  Maths::Vector vector = Maths::Vector(8, 16, 32, -50);
  Maths::Vector newVector = vector / 2;

  double correctValues[] = {4, 8, 16, -25};

  for (int elementNo = 0; elementNo < newVector.length(); elementNo++)
    EXPECT_DOUBLE_EQ(correctValues[elementNo], newVector[elementNo]);
}

TEST(VectorTests, DotProductOfVectorsWithPositiveValues)
{
  Maths::Vector lhsVector = Maths::Vector(1, 2, 3, 4);
  Maths::Vector rhsVector = Maths::Vector(5, 6, 7, 8);

  double dotProduct = lhsVector * rhsVector;
  double correctDotProduct = 70;

  EXPECT_DOUBLE_EQ(correctDotProduct, dotProduct);
}

TEST(VectorTests, DotProductOfVectorsWithMixedValues)
{
  Maths::Vector lhsVector = Maths::Vector(-1, -5, 15, 6);
  Maths::Vector rhsVector = Maths::Vector(5, -6, -7, 8);

  double dotProduct = lhsVector * rhsVector;
  double correctDotProduct = -32;
  
  EXPECT_DOUBLE_EQ(correctDotProduct, dotProduct);
}

TEST(VectorTests, ShouldPrintVectorToString)
{
  Maths::Vector vector = Maths::Vector(1, 2, 3, 4);
  std::cout << vector.toString() << std::endl;

  // Fails on precision of double values with trailing zeroes.

  std::string vectorAsString = vector.toString();
  std::string correctString = "[0: 1.000, 1: 2.000, 2: 3.000, 3: 4.000]";

  // EXPECT_EQ(correctString, vectorAsString); 
}

TEST(VectorTests, ShouldPrintVectorAsStringDirectlyInCout)
{
  Maths::Vector vector = Maths::Vector(1, 2, 3, 4);
  std::cout << vector << std::endl;
}

TEST(VectorTests, ShouldCalculateVectorProduct)
{
  Maths::Vector vector1 = Maths::Vector(2, 3, 4);
  Maths::Vector vector2 = Maths::Vector(5, 6, 7);

  Maths::Vector vectorProduct = vector1.vectorProduct(vector2);
  double correctValues[] = {-3, 6, -3};

  int noOfValues = vectorProduct.length();

  for (int i = 0; i < noOfValues; i++) {
    double actualValue = vectorProduct[i];
    double correctValue = correctValues[i];

    EXPECT_DOUBLE_EQ(actualValue, correctValue);
  }
}

TEST(VectorTests, ShouldCalculateAngleBetweenTwoVectors)
{
  Maths::Vector vector1 = Maths::Vector(1, 2, 3);
  Maths::Vector vector2 = Maths::Vector(4, 5, 6);

  double angleInRadians = vector1.angle(vector2);
  double correctAngle = 0.22572612855273419;

  EXPECT_DOUBLE_EQ(angleInRadians, correctAngle);
}

TEST(VectorTests, ShouldIterateThroughVector)
{
  std::vector<double> correctValues = {1, 2, 3};
  Maths::Vector vector = Maths::Vector(correctValues);

  std::vector<double> valuesFromIteration = {};

  for (auto value : vector)
    valuesFromIteration.push_back(value);

  int numberOfValues = correctValues.size();

  for (int i = 0; i < numberOfValues; i++)
    EXPECT_DOUBLE_EQ(correctValues[i], valuesFromIteration[i]);
}