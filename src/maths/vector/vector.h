#include <iostream>
#include "src/common/arrays.h"
#include "src/maths/binary_ops/binary_ops.h"

using namespace std;
using namespace BinaryOps;

namespace Vectorable
{
  class Vector
  {
    public:
  
      /**
       * Creates a new vector with an array of doubles as the vector
       * elements. Requires the length of the array to be passed in
       * manually as second parameter due to the array C++ primitive
       * not knowing its length once passed to a function.
       */
      Vector(double array[], int noOfArrayElements);

      // Creates a new vector using the parameters as vector points.
      Vector(double a, double b);
      
      // Creates a new vector using the parameters as vector points.
      Vector(double a, double b, double c);
      
      // Creates a new vector using the parameters as vector points.
      Vector(double a, double b, double c, double d);

      /**
       * Returns the scalar/dot product from this vector with another
       * vector.
       */
      double dotProduct(Vector vector);

      /**
       * Returns a vector formed from the vector/cross product of this
       * vector with another vector. Only works with 3D vectors at the
       * moment.
       */
      Vector vectorProduct(Vector vector);

      // Calculates the angle between this vector and another vector.
      double angle(Vector vector);

      // Returns the length of the vector.
      int length();

      // Returns the magnitude of the vector.
      double magnitude();

      // Gets the vector element by index position.
      double get(int index);

      // Indexes the elements contained within the vector.
      double operator [] (int index);

      /**
       * Returns a new vector forming from the addition of this vector
       * with another vector.
       */
      Vector operator + (Vector vectorRhs);

      /**
       * Returns a new vector forming from the difference of this
       * vector with another vector.
       */ 
      Vector operator - (Vector vectorRhs);

      // Returns the dot product of this vector with another vector.
      double operator * (Vector vectorRhs);

      // Returns a new vector using scalar multiplication.
      Vector operator * (double scalarRhs);

      // Returns a new vector using scalar division.
      Vector operator / (double scalar);

      // Returns a string representation of the vector.
      string toString();

    private:
      int lengthOfVector;
      double *vectorArray;
      
      /**
       * Takes a binary operation and performs it with this vector
       * against another vector.
       */
      Vector performBinaryOperationWithVector(
        Vector vector, BinaryOperation *operation);
      
      /**
       * Takes a binary operation and performs it with this vector
       * against a scalar quantity.
       */
      Vector performBinaryOperationWithScalar(
        double scalar, BinaryOperation *operation);

      /**
       * Multiplies the elements of two vectors together and returns
       * an arraylist type so the length value of the array can be
       * ascertained if required.
       */
      ArrayList<double> multiplyElements(Vector vector);
      
      /**
       * Assigns an array pointer and its corresponding length against
       * this vector.
       */
      void assignArrayAndVectorLength(double *array, int length);
      
      // Creates a copy of an array.
      double* copyArray(double *array, int length);
      
      /**
       * Returns an array containing the values found when performing
       * the cross product of this vector with another vector. Only works
       * for vectors of length 3.
       */
      double* calculateCrossProductCoordinates(Vector vector);
      
      // Squares a number and adds it to a sum value.
      double squareNumberAndAddToSum(double number, double sum);
      
      // Returns a string representation of a point.
      string getPointAsString(int pointIndex);
  };
}

using namespace Vectorable;

/**
 * Overloaded * operator that allows multiplication between a scalar
 * double on the LHS and a vector on the RHS.
 */
Vector operator * (double scalarLhs, Vector vectorRhs);

/**
 * Allows the vector to be printed to cout directly as an object with
 * toString() needing to be called.
 */
ostream& operator << (ostream &_stream, Vector v);