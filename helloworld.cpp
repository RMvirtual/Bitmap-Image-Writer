#include <iostream>
using namespace std;

class PrintableMessage
{
    public: string messageToPrint = "Hello World!";
};

int main()
{
    PrintableMessage message = PrintableMessage();
    cout << message.messageToPrint;
    return 0;
}