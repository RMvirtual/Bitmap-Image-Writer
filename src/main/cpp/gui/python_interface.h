#include <string>
#include "python.h"

namespace GUI {
class PythonInterface
{
public:
  PythonInterface();
  ~PythonInterface();

  void initialise();
  void start();
  void close();
  void setupGUI();
  void loadImage(std::string imagePath);
  void refresh();
  void show();

private:
  PyObject* gui;

  void loadPythonLibraries();
};}