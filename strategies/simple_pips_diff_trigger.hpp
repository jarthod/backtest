#include "strategy.hpp"

class SimplePipsDiffTrigger: public Strategy
{
public:

  SimplePipsDiffTrigger(float trigger);
  void      tick(const Tick& tick);

private:

  float     min;
  float     max;
  float     trigger;
};