#pragma once

#include "src/main/cpp/app/demo/interface/demo.h"
#include "src/main/cpp/gui/python_interface.h"

namespace Demo {
class TextDemo : public Demo
{
public:
  TextDemo();
  
  void start();

private:
  GUI::PythonInterface interface;

};}