#include "binary_ops.h";

using namespace BinaryOps;

BinaryOperation::BinaryOperation()
{
    // Nothing else to do here.
}

Add::Add()
: BinaryOperation()
{
    // Nothing else to do.
}

double Add::perform(double left, double right)
{
    return left + right;
}

Subtract::Subtract()
: BinaryOperation()
{
    // Nothing else to do.
}

double Subtract::perform(double left, double right)
{
    return left - right;
}