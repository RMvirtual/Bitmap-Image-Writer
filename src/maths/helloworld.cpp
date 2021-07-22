#include <iostream>
#include "printablemessage.h"

using namespace std;
using namespace Printable;

int main()
{
    PrintableMessage message = PrintableMessage("Aight");
    cout << message.getMessage();    
    cout << "\nChanging message.";
    message.setMessage("I am a new message.");
    cout << "\n" + message.getMessage();

    return 0;
}