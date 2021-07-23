#include <iostream>

namespace Vectorable
{
    class Vector
    {
        public:
            Vector();
            Vector(double a[]);
            Vector(double a, double b);
            int& operator [](int i);
            int length();
            double magnitude();
    };
}