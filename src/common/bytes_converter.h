#include <cstdint>
#include <string>

using namespace std;

class BytesConverter
{
public:
  uint32_t convertFourCharactersTo32bitInteger(string stringToConvert);
  uint16_t convertTwoCharactersTo16bitInteger(string stringToConvert);

};