#include "test/src/bitmaps/fixtures/test.h"

class BitmapFormatsTest : public BitmapTest
{
public:
  BitmapFormatsTest();
  ~BitmapFormatsTest();

protected:
  void initialiseRgbaFormat();
  void initialiseRgbFormat();
};