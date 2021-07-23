namespace Vectorable
{
    class Vector
    {
        public:
            Vector(double array[], int noOfArrayElements);
            Vector(double a, double b);
            Vector(double a, double b, double c);
            Vector(double a, double b, double c, double d);

            int& operator [](int i);
            int length();
            double magnitude();
            double get(int index);
            double *vectorArray;

        private:
            int lengthOfVector;
    };
}