#include <string>

using namespace std;

class Position
{
public:

  enum Type { SHORT = -1, LONG = 1 };

  float     pips() const;
  float     gain() const;

  Type      type;
  string    open_time, close_time;
  float     open_price, close_price;
  float     lots;
};