#include "gtest/gtest.h"
#include "src/main/cpp/gui/python_interface.h"

TEST(GUIInterfaceTest, ShouldStartGUI)
{
  GUI::GUIInterface interface;
  interface.start();
  interface.doSomething();
  interface.close();

  EXPECT_TRUE(true);
}