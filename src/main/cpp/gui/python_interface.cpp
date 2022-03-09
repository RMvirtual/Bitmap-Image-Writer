#include "src/main/cpp/gui/python_interface.h"
#include "python.h"

GUI::GUIInterface::GUIInterface()
{
  Py_Initialize();  
}

void GUI::GUIInterface::start()
{
  // pass.  
}