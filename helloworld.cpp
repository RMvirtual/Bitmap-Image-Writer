#include <iostream>
#include <boost/lambda/lambda.hpp>
#include <iterator>
#include <algorithm>

using namespace std;
using namespace boost::lambda;

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

    public: void setMessage3(string message)
    {
        this->message3 = message;
    }
};

int main()
{
    PrintableMessage message = PrintableMessage("Aight");
    cout << message.getMessage3();
    
    cout << "\nChanging message 3.";
    message.setMessage3("Too many chars?");
    cout << "\n" + message.getMessage3();

    return 0;
}