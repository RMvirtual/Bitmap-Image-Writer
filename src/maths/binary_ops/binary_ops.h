namespace BinaryOps
{
    class BinaryOperation
    {
        public:
            BinaryOperation();
            virtual double perform(double left, double right) = 0;
    };

    class Add : public BinaryOperation
    {
        public:
            Add();
            double perform(double a, double b);
    };

    class Subtract : public BinaryOperation
    {
        public:
            Subtract();
            double perform(double a, double b);
    };
}