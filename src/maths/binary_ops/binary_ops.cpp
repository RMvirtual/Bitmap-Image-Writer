#include "binary_ops.h";

using namespace BinaryOps;

BinaryOperation::BinaryOperation(double left, double right)
{
    this->left = left;
    this->right = right;
}

double BinaryOperation::getLeft()
{
    return this->left;
}

double BinaryOperation::getRight()
{
    return this->right;
}

Add::Add(double left, double right)
: BinaryOperation(left, right)
{
    // Nothing else to do.
}

double Add::perform()
{
    double left = this->getLeft();
    double right = this->getRight();

    return left + right;
}

Subtract::Subtract(double left, double right)
: BinaryOperation(left, right)
{
    // Nothing else to do.
}

double Subtract::perform()
{
    double left = this->getLeft();
    double right = this->getRight();

    return left - right;
}