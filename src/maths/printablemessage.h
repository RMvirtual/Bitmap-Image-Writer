#include <iostream>

using namespace std;

namespace Printable
{
    class PrintableMessage
    {
        public:
            PrintableMessage(string privateMessage);
            string getMessage();
            void setMessage(string message);
            string message;
    };
}