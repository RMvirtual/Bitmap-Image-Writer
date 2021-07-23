namespace Vectorable
{
    class Vector
    {
        public:
            Vector();
            Vector(double a[]);
            Vector(double x, double y);
            int& operator [](int i);
            int length();
            double magnitude();
            double get(int index);
            double *vectorArray;
    };
}