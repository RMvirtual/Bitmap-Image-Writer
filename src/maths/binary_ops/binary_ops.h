

namespace BinaryOps
{
    class BinaryOperation
    {
        public:
            BinaryOperation(double left, double right);
            virtual double perform() = 0;
            void setLeft(double value);
            void setRight(double value);
            double getLeft();
            double getRight();

        private:
            double left;
            double right;
    };

    class Add:BinaryOperation
    {
        public:
            Add(double a, double b);
            double perform();
    };
}