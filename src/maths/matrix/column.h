#include <iterator>
#include <vector>

using namespace std;

class Column
{
public:
  Column(std::vector<double> vector);
  double operator[](int index);
  int size();
  vector<double> toVector();
  
private:
  vector<double> vector;
};