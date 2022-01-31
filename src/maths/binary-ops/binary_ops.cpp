#include "src/maths/binary-ops/binary_ops.h";

double Maths::Addition::perform(double left, double right)
{
  return left + right;
}

double Maths::Subtraction::perform(double left, double right)
{
  return left - right;
}

double Maths::Multiplication::perform(double left, double right)
{
  return left * right;
}

double Maths::Division::perform(double left, double right)
{
  return left / right;
}

Maths::BinaryOperation::BinaryOperation()
{
  // Pass.
}

Maths::Addition::Addition()
: BinaryOperation()
{
  // Pass.
}

Maths::Subtraction::Subtraction()
: BinaryOperation()
{
  // Pass.
}

Maths::Multiplication::Multiplication()
: BinaryOperation()
{
  // Pass.
}

Maths::Division::Division()
: BinaryOperation()
{
  // Pass.
}