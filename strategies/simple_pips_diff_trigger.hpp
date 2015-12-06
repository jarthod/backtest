#include "strategy.hpp"

class SimplePipsDiffTrigger: public Strategy
{
public:

  SimplePipsDiffTrigger(float trigger = 1);
  void      tick(const Tick& tick);

private:

  float     min;
  float     max;
  float     trigger;
};