#include "gtest/gtest.h"

#include <iostream>
#include "src/gui/app.h"

TEST(GuiTest, ShouldGetWxWidget)
{
  GUIApp app {};
  app.OnInit();
  EXPECT_TRUE(true);
}