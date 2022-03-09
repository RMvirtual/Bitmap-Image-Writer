#include "src/main/cpp/gui/python_interface.h"
#include "python.h"

GUI::PythonInterface::PythonInterface()
{
  this->initialise();
}

GUI::PythonInterface::~PythonInterface()
{
  this->close();
}

void GUI::PythonInterface::initialise()
{
  Py_Initialize();
  this->setSrcPath();
  this->initialiseBootstrapper();
  this->initialiseGUI(); 
}

void GUI::PythonInterface::setSrcPath()
{
  PyRun_SimpleString(
    "import sys\n"
    "sys.path.append(\"C:/Users/rmvir/Desktop/scc300-Win3D\")\n"
  );
}

void GUI::PythonInterface::initialiseGUI()
{
  PyObject *pName, *pModule, *pDict, *viewerClass, *guiObject;

  pName = PyUnicode_FromString("src.main.python.gui.viewer.viewer");
  pModule = PyImport_Import(pName);
  Py_DECREF(pName);

  if (pModule != NULL) {
    pDict = PyModule_GetDict(pModule);

    if (pDict != NULL) {
      Py_DECREF(pModule);

      viewerClass = PyDict_GetItemString(pDict, "GUI");

      if (viewerClass != NULL) {
        Py_DECREF(pDict);

        if (PyCallable_Check(viewerClass)) {
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
  Py_DECREF(pName);

  if (pModule != NULL) {
    pDict = PyModule_GetDict(pModule);

    if (pDict != NULL) {
      Py_DECREF(pModule);

      viewerClass = PyDict_GetItemString(pDict, "GUIBootstrapper");

      if (viewerClass != NULL) {
        Py_DECREF(pDict);

        if (PyCallable_Check(viewerClass)) {
          guiObject = PyObject_CallObject(viewerClass, nullptr);
          Py_DECREF(viewerClass);
        }
      }
    }

    this->bootstrapper = guiObject;
  }
}

void GUI::PythonInterface::loadImage(std::string imagePath)
{
  PyObject* method = PyUnicode_FromString("loadImage");
  PyObject* parameters = PyUnicode_FromString(imagePath.c_str());
  PyObject_CallMethodOneArg(this->gui, method, parameters);

  Py_DECREF(method);
  Py_DECREF(parameters);
}

void GUI::PythonInterface::show()
{
  PyObject_CallMethod(this->gui, "show", NULL);
}

void GUI::PythonInterface::refresh()
{
  PyObject_CallMethod(this->gui, "refreshImage", NULL); 
}

void GUI::PythonInterface::launchMainLoop()
{
  PyObject_CallMethod(this->bootstrapper, "launchMainLoop", NULL); 
}

void GUI::PythonInterface::close()
{
  Py_Finalize();
}