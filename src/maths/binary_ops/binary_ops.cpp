#include "binary_ops.h";

using namespace BinaryOps;

double Addition::perform(double left, double right)
{
  return left + right;
}

double Subtraction::perform(double left, double right)
{
  return left - right;
}

double Multiplication::perform(double left, double right)
{
  return left * right;
}

double Division::perform(double left, double right)
{
  return left / right;
}

BinaryOperation::BinaryOperation()
{
  // Pass.
}

Addition::Addition()
: BinaryOperation()
{
  // Pass.
}

Subtraction::Subtraction()
: BinaryOperation()
{
  // Pass.
}

Multiplication::Multiplication()
: BinaryOperation()
{
  // Pass.
}

Division::Division()
: BinaryOperation()
{
  // Pass.
}