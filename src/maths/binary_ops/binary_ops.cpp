#include "binary_ops.h";

using namespace BinaryOps;

BinaryOperation::BinaryOperation()
{
    // Nothing else to do here.
}

Addition::Addition()
: BinaryOperation()
{
    // Nothing else to do.
}

double Addition::perform(double left, double right)
{
    return left + right;
}

Subtraction::Subtraction()
: BinaryOperation()
{
    // Nothing else to do.
}

double Subtraction::perform(double left, double right)
{
    return left - right;
}

Multiplication::Multiplication()
: BinaryOperation()
{
    // Nothing else to do.
}

double Multiplication::perform(double left, double right)
{
    return left * right;
}

Division::Division()
: BinaryOperation()
{
    // Nothing else to do.
}

double Division::perform(double left, double right)
{
    return left / right;
}