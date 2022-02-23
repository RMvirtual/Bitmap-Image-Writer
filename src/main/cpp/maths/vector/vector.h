#ifndef VECTOR_H
#define VECTOR_H

#include <array>
#include <cstdarg>
#include <iostream>
#include <string>
#include <vector>

#include "src/main/cpp/maths/binary-ops/binary_ops.h"

namespace Maths
{
  class Vector
  {
  public:
    // Creates an empty vector.
    Vector();

    /**
     * Creates a new vector with an array of doubles as the vector
     * elements. Requires the length of the array to be passed in
     * manually as second parameter due to the array C++ primitive
     * not knowing its length once passed to a function.
     */
    Vector(double array[], int noOfValues);
    Vector(double a, double b);
    Vector(double a, double b, double c);
    Vector(double a, double b, double c, double d);
    Vector(const std::vector<double>& values);

    /**
     * Returns the scalar/dot product from this vector with another
     * vector.
     */
    double dotProduct(const Vector& vector) const;

    /**
     * Returns a vector formed from the vector/cross product of this
     * vector with another vector. Only works with 3D vectors at the
     * moment.
     */
    Vector vectorProduct(const Vector& vector);

    // Calculates the angle between this vector and another vector.
    double angle(const Vector& vector) const;

    // Returns the length of the vector.
    int length() const;

    // Returns the magnitude of the vector.
    double magnitude() const;

    // Gets the vector element by index position.
    double get(int index) const;

    // Indexes the elements contained within the vector.
    double operator [](int index) const;

    /**
     * Returns a new vector forming from the addition of this vector
     * with another vector.
     */
    Vector operator +(const Vector& vectorRhs) const;

    /**
     * Returns a new vector forming from the difference of this
     * vector with another vector.
     */
    Vector operator -(const Vector& vectorRhs) const;

    // Returns the dot product of this vector with another vector.
    double operator *(const Vector& vectorRhs) const;

    // Returns a new vector using scalar multiplication.
    Vector operator *(double scalarRhs) const;

    // Returns a new vector using scalar division.
    Vector operator /(double scalar) const;

    // Returns a string representation of the vector.
    std::string toString() const;

    // Returns an iterator at the start of the vector's values.
    std::vector<double>::iterator begin();

    // Returns an iterator at the end of the vector's values.
    std::vector<double>::iterator end();

    // Returns a constant iterator at the start of the vector's values.
    std::vector<double>::const_iterator begin() const;

    // Returns a constant iterator at the end of the vector's values.
    std::vector<double>::const_iterator end() const;

  private:
    std::vector<double> values;

    /**
     * Takes a binary operation and performs it with this vector
     * against another vector.
     */
    template<class BinaryOperation>
    Vector performBinaryOperation(const Vector& vector) const;

    /**
     * Takes a binary operation and performs it with this vector
     * against a scalar quantity.
     */
    template<class BinaryOperation>
    Vector performBinaryOperation(double scalar) const;

    /**
     * Multiplies the elements of two vectors together and returns
     * an arraylist type so the length value of the array can be
     * ascertained if required.
     */
    std::vector<double> multiplyElements(const Vector& vector) const;

    /**
       * Assigns an array pointer and its corresponding length against
       * this vector.
       */
    void createVectorFromArray(double *array, int length);

    /**
     * Returns an STL vector containing the values found when
     * performing the cross product of this vector with another
     * vector. Only works for vectors of length 3.
     */
    std::vector<double> calculateCrossProductValues(
      const Vector& vector) const;

    // Returns a string representation of a point.
    std::string getPointAsString(int pointIndex) const;

    /**
     * Returns each string representation of every point,
     * concatenated together by a comma and a space (excluding the
     * last point).
     */
    std::string getAllPointsAsString() const;
  };
}

/**
 * Overloaded * operator that allows multiplication between a scalar
 * double on the LHS and a vector on the RHS.
 */
Maths::Vector operator * (double scalarLhs, const Maths::Vector& vectorRhs);

/**
 * Allows the vector to be printed to cout directly as an object with
 * toString() needing to be called.
 */
std::ostream &operator << (std::ostream &_stream, const Maths::Vector& vector);

#endif