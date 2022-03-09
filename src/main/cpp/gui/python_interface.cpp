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
  PyObject *pName, *pModule, *pDict, *viewerClass, *guiObject;
  PyObject *pArgs, *pValue;
  
  pName = PyUnicode_FromString("src.main.python.gui.viewer.viewer");
  pModule = PyImport_Import(pName);
  std::cout << "Gets name.\n";
  Py_DECREF(pName);

  if (pModule != NULL) {
    std::cout << "Gets module.\n";
    pDict = PyModule_GetDict(pModule);

    if (pDict != NULL) {
      std::cout << "Gets dict.\n";
      Py_DECREF(pModule);

      viewerClass = PyDict_GetItemString(pDict, "GUI");

      if (viewerClass != NULL) {
        std::cout << "Gets Python class.\n";
        Py_DECREF(pDict);

        if (PyCallable_Check(viewerClass)) {
          std::cout << "Class is callable.\n";
          guiObject = PyObject_CallObject(viewerClass, nullptr);
          Py_DECREF(viewerClass);
        }
      }
    }
  }

  // PyObject* tp_call(PyObject *callable, PyObject *args, PyObject *kwargs);
}

void GUI::GUIInterface::doSomething()
{
  PyRun_SimpleString(
    "print('Hello, world!')\n"
  );
}

void GUI::GUIInterface::close()
{
  Py_Finalize();
}