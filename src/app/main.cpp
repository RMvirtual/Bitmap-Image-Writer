// Your First C++ Program

#include <iostream>
#include "src/gui/app.h"

int main() {
    GUIApp app {};
    app.OnInit();
    std::cout << "Hello World!";
    return 0;
}