#include "printablemessage.h"
#include <iostream>

using namespace Printable;
using namespace std;

PrintableMessage::PrintableMessage(string privateMessage)
{
    this->message = privateMessage;
}

string PrintableMessage::getMessage()
{
    return this->message;
}

void PrintableMessage::setMessage(string message)
{
    this->message = message;
}