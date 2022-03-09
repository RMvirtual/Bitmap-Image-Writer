#include <string>
#include "python.h"

namespace GUI {
class PythonInterface
{
public:
  PythonInterface();
  ~PythonInterface();

  void initialise();
  void initialiseBootstrapper();
  void initialiseGUI();
  void launchMainLoop();
  void close();
  void loadImage(std::string imagePath);
  void refresh();
  void show();

private:
  PyObject* bootstrapper;
  PyObject* gui;

  void setSrcPath();
};}