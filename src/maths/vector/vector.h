#include <iostream>>

using namespace std;

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
            double add(double left, double right);
            double subtract(double left, double right);
            double binary_operation(
                double left, double right,
                double (*operationFunction)(double, double)
            );

            int lengthOfVector;
    };
}

using namespace Vectorable;

Vector operator * (double scalarLHS, Vector vectorRHS);
ostream& operator << (ostream &_stream, Vector v);