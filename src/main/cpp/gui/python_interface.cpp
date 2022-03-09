#include "src/main/cpp/gui/python_interface.h"
#include "python.h"

#include <iostream>

GUI::PythonInterface::PythonInterface()
{
  Py_Initialize();

  PyRun_SimpleString(
    "import sys\n"
    "sys.path.append(\"C:/Users/rmvir/Desktop/scc300-Win3D\")\n"
  );

  this->start();
}

GUI::PythonInterface::~PythonInterface()
{
  this->close();
}

void GUI::PythonInterface::start()
{
  this->initialiseBootstrapper();
  this->initialiseGUI(); 
}

void GUI::PythonInterface::loadImage(std::string imagePath)
{
  PyObject* method = PyUnicode_FromString("refreshImage");
  PyObject* parameters = PyUnicode_FromString(imagePath.c_str());
  PyObject_CallMethodOneArg(this->gui, method, parameters);

  Py_DECREF(method);
  Py_DECREF(parameters);
}

void GUI::PythonInterface::show()
{
  PyObject_CallMethod(this->gui, "Show", NULL); 
}

void GUI::PythonInterface::refresh()
{
  PyObject_CallMethod(this->gui, "refreshImage", NULL); 
}

void GUI::PythonInterface::launchMainLoop()
{
  PyObject_CallMethod(this->bootstrapper, "launchMainLoop", NULL); 
}

void GUI::PythonInterface::initialiseGUI()
{
  PyObject *pName, *pModule, *pDict, *viewerClass, *guiObject;

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

  this->gui = guiObject;
}

void GUI::PythonInterface::initialiseBootstrapper()
{
  PyObject *pName, *pModule, *pDict, *viewerClass, *guiObject;

  // Bootstrapper.
  pName = PyUnicode_FromString(
    "src.main.python.gui.bootstrapper.bootstrapper");
  pModule = PyImport_Import(pName);
  std::cout << "Gets name.\n";
  Py_DECREF(pName);

  if (pModule != NULL) {
    std::cout << "Gets module.\n";
    pDict = PyModule_GetDict(pModule);

    if (pDict != NULL) {
      std::cout << "Gets dict.\n";
      Py_DECREF(pModule);

      viewerClass = PyDict_GetItemString(pDict, "GUIBootstrapper");

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

    this->bootstrapper = guiObject;
  }
}

void GUI::PythonInterface::close()
{
  Py_Finalize();
}