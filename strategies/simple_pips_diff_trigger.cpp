#include "simple_pips_diff_trigger.hpp"

SimplePipsDiffTrigger::SimplePipsDiffTrigger(float trigger)
{
  this->trigger = trigger;
  this->min = 1000000;
  this->max = 0;
  char buff[100];
  sprintf(buff, "t=%.3f", trigger);
  this->_name = buff;
}

void  SimplePipsDiffTrigger::tick(const Tick& tick)
{
  if (short_positions.empty() && tick.bid < (max - trigger)) // Go short
  {
    if (!long_positions.empty())
      close_buy();
    sell();
    max = 0;
  }
  if (long_positions.empty() && tick.ask > (min + trigger)) // Go long
  {
    if (!short_positions.empty())
      close_sell();
    buy();
    min = 1000000;
  }
  if (tick.ask < min)
    min = tick.ask;
  if (tick.bid > max)
    max = tick.bid;
}