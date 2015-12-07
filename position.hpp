#include <string>
#include <cmath>

using namespace std;

class Position
{
public:

  enum Type { SHORT = -1, LONG = 1 };

  float     diff() const;
  float     gain() const;

  Type      type;
  int       open_time, close_time;
  float     open_price, close_price;
  float     lots;
  float     fee;
};