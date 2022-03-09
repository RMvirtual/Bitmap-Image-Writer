#include "src/main/cpp/gui/python_interface.h"
#include "python.h"

#include <iostream>

GUI::GUIInterface::GUIInterface()
{
  Py_Initialize();
  PyRun_SimpleString(
    "import sys\n"
    "sys.path.append(\"C:/Users/rmvir/Desktop/scc300-Win3D\")\n"
  );
}

void GUI::GUIInterface::start()
{
  PyObject *pName, *pModule, *pDict, *pFunc;
  PyObject *pArgs, *pValue;
  
  pName = PyUnicode_FromString("src.main.python.gui.viewer");
  pModule = PyImport_Import(pName);

  std::cout << *Py_GetPath() << std::endl;

  Py_DECREF(pName);

  if (pModule != NULL) {
    std::cout << "Seems to import module." << std::endl;
  }

  // PyObject* tp_call(PyObject *callable, PyObject *args, PyObject *kwargs);
}

void GUI::GUIInterface::doSomething()
{
  PyRun_SimpleString(
    "import os\n"
    "cwd = os.getcwd()\n"
    "print(cwd)\n"
  );
}

void GUI::GUIInterface::close()
{
  Py_Finalize();
}