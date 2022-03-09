#include "src/main/cpp/gui/python_interface.h"
#include "python.h"

#include <iostream>

GUI::GUIInterface::GUIInterface()
{
  Py_Initialize();
}

void GUI::GUIInterface::start()
{
  PyObject *pName, *pModule, *pDict, *pFunc;
  PyObject *pArgs, *pValue;
  
  pName = PyUnicode_FromString(
    (char*) "C:/Users/rmvir/Desktop/scc300-Win3D/src/main/python/gui/viewer.py");

  pModule = PyImport_Import(pName);

  Py_DECREF(pName);

  if (pModule != NULL) {
    std::cout << "Seems to import module." << std::endl;
  }

  // PyObject* tp_call(PyObject *callable, PyObject *args, PyObject *kwargs);
}

void GUI::GUIInterface::doSomething()
{
  PyRun_SimpleString(
    "from time import time,ctime\n"
    "print('Today is',ctime(time()))\n"
  );
}

void GUI::GUIInterface::close()
{
  Py_Finalize();
}