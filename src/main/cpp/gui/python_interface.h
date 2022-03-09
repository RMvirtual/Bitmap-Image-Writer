#include "python.h"

namespace GUI {
class GUIInterface
{
public:
  GUIInterface();

  void start();
  void launchBootstrapper();
  void launchGUI();

  void doSomething();
  void close();
private:
  PyObject* bootstrapper;
  PyObject* gui;
};}