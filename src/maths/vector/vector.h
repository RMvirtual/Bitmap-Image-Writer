#include <iostream>>

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
            std::string toString();

            int length();
            double magnitude();
            double get(int index);

        private:
            int lengthOfVector;
    };
}

Vectorable::Vector operator * (double scalarLHS, 
    Vectorable::Vector vectorRHS);

std::ostream& operator << (std::ostream &_stream, Vectorable::Vector v);