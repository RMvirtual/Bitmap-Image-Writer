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
            double perform(double left, double right);
    };

    class Subtraction : public BinaryOperation
    {
        public:
            Subtraction();
            double perform(double left, double right);
    };

    class Multiplication : public BinaryOperation
    {
        public:
            Multiplication();
            double perform(double left, double right);
    };

    class Division : public BinaryOperation
    {
        public:
            Division();
            double perform(double left, double right);
    };
}