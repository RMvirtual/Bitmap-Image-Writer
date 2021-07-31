namespace BinaryOps
{
    class BinaryOperation
    {
        public:
            BinaryOperation();
            virtual double perform(double left, double right) = 0;
    };

    class Addition : public BinaryOperation
    {
        public:
            Addition();
            double perform(double a, double b);
    };

    class Subtraction : public BinaryOperation
    {
        public:
            Subtraction();
            double perform(double a, double b);
    };

    class Multiplication : public BinaryOperation
    {
        public:
            Multiplication();
            double perform(double a, double b);
    };

    class Division : public BinaryOperation
    {
        public:
            Division();
            double perform(double a, double b);
    };
}