#include <iostream>
#include "../../common/arrays.h"
#include "../binary_ops/binary_ops.h"

using namespace std;
using namespace BinaryOps;
using namespace Arrays;

namespace Vectorable
{
    class Vector
    {
        public:
            Vector(double array[], int noOfArrayElements);
            Vector(double a, double b);
            Vector(double a, double b, double c);
            Vector(double a, double b, double c, double d);

            double *vectorArray;

            double operator [] (int index);
            Vector operator + (Vector righthandsideVector);
            Vector operator - (Vector righthandsideVector);
            double operator * (Vector righthandsideVector);
            Vector operator * (double righthandsideScalar);
            Vector operator / (double scalar);
            string toString();

            int length();
            double magnitude();
            double get(int index);

        private:            
            Vector performBinaryOperationWithVector(
                Vector rhsVector, BinaryOperation *operation);
            
            Vector performBinaryOperationWithScalar(
                double scalar, BinaryOperation *operation);

            double dotProduct(Vector vector);
            ArrayList<double> multiplyElements(Vector vector);
            int lengthOfVector;
    };
}

using namespace Vectorable;

Vector operator * (double scalarLHS, Vector vectorRHS);
ostream& operator << (ostream &_stream, Vector v);