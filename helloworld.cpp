#include <iostream>
using namespace std;

class PrintableMessage
{
    public:
        string message1 = "Hello World!";
        string message2 = "Bonjour";
    private:
        string message3;

    public: PrintableMessage(string privateMessage)
    {
        message3 = privateMessage;
    }

    public: string getMessage3()
    {
        return this->message3;
    }

};

int main()
{
    PrintableMessage message = PrintableMessage("Aight");
    cout << message.getMessage3();
    return 0;
}