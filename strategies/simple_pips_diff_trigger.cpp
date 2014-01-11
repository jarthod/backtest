#include "simple_pips_diff_trigger.hpp"

SimplePipsDiffTrigger::SimplePipsDiffTrigger(float trigger = 0.004)
{
  this->trigger = trigger;
  this->min = 1000000;
  this->max = 0;
  char buff[100];
  sprintf(buff, "Simple (t=%.3f)", trigger);
  this->name = buff;
}

void  SimplePipsDiffTrigger::tick(const Tick& tick)
{
  if (long_positions.empty() && tick.ask > (min + trigger)) // Go long
  {
    if (!short_positions.empty())
      close_sell();
    buy();
    max = 0;
  }
  if (short_positions.empty() && tick.bid < (max - trigger)) // Go short
  {
    if (!long_positions.empty())
      close_buy();
    sell();
    min = 1000000;
  }
  if (tick.ask < min)
    min = tick.ask;
  if (tick.bid > max)
    max = tick.bid;
}