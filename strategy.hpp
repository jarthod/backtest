#include <vector>
#include "circular_buffer.hpp"
#include "tick.hpp"
#include "position.hpp"

using namespace std;

class Strategy
{
public:

  Strategy();

  // Called when a new tick arrives on the market
  void          new_tick(const Tick& tick);
  float         gain() const;
  const vector<Position>& positions() const;
  const string& name() const;

protected:

  // Methods dedicated to implementations (subclasses)
  virtual void  tick(const Tick& tick) = 0;
  void          buy(float lots = 1);
  void          sell(float lots = 1);
  void          close_buy();
  void          close_sell();

  CircularBuffer<Tick>  last_ticks;
  vector<Position>      long_positions;
  vector<Position>      short_positions;
  string                _name;

private:

  vector<Position>      history;
  float                 _gain;
  float                 spread;
  float                 fee;
};
