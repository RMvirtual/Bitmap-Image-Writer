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

bool GUI::GUIInterface::isRunning()
{
  return true;
}

void GUI::GUIInterface::doSomething()
{
  PyRun_SimpleString(
    "from time import time,ctime\n"
    "print('Today is',ctime(time()))\n"
  );
}