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

            double operator[](int index);
            Vector operator+(Vector righthandsideVector);
            Vector operator-(Vector righthandsideVector);
            double operator*(Vector righthandsideVector);
            Vector operator*(double righthandsideScalar);
            // friend Vector operator*(double left, Vector right);
            Vector operator/(double scalar);

            int length();
            double magnitude();
            double get(int index);


        private:
            int lengthOfVector;
    };
}

char operator+(double lhs, Vectorable::Vector rhs);

Vectorable::Vector operator*(
    const double scalarLHS, const Vectorable::Vector& vectorRHS);

