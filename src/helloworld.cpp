#include <iostream>
#define BOOST_TEST_MODULE First_TestSuite
#include <boost/test/included/unit_test.hpp>

using namespace boost::unit_test;
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

    public: void setMessage3(string message)
    {
        this->message3 = message;
    }
};

BOOST_AUTO_TEST_CASE(myTest)
{
    BOOST_CHECK(2 + 2 == 4);
    BOOST_CHECK(3 + 1 == 3);
}

/*
int main()
{
    PrintableMessage message = PrintableMessage("Aight");
    cout << message.getMessage3();
    
    cout << "\nChanging message 3.";
    message.setMessage3("Too many chars?");
    cout << "\n" + message.getMessage3();

    return 0;
}
*/