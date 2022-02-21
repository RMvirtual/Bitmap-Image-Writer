// Your First C++ Program

#include <iostream>
#include "src/gui/app.h"

int main() {
    GUIApp* app = new GUIApp();
    bool hasRun = app->OnInit();

    app->window->Show();

    if (hasRun) {
        std::cout << "Gets to end of main().\n";
    }
}