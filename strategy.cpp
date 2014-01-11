#include "strategy.hpp"

Strategy::Strategy()
{
  this->gain = 0;
  this->name = "Strategy";
}

void  Strategy::new_tick(const Tick& tick)
{
  last_ticks.insert(tick);
  this->tick(tick);
}

void  Strategy::print_state() const
{
  printf("%6dt %+6.1fp", history.size(), gain);
}

void  Strategy::buy(float lots)
{
  Position pos;

  pos.type = Position::Type::LONG;
  pos.open_price = last_ticks.get(0).ask;
  pos.open_time = last_ticks.get(0).time;
  pos.lots = lots;

  long_positions.push_back(pos);
}

void  Strategy::sell(float lots)
{
  Position pos;

  pos.type = Position::Type::SHORT;
  pos.open_price = last_ticks.get(0).bid;
  pos.open_time = last_ticks.get(0).time;
  pos.lots = lots;

  short_positions.push_back(pos);
}

void Strategy::close_buy()
{
  Position pos = long_positions.back();

  long_positions.pop_back();
  pos.close_price = last_ticks.get(0).bid;
  pos.close_time = last_ticks.get(0).time;
  history.push_back(pos);

  gain += pos.gain();
  // printf("close  LONG %f -> %f (%+5.1f pips) gain: %+.1f\n", pos.open_price, pos.close_price, pos.pips(), gain);
}

void Strategy::close_sell()
{
  Position pos = short_positions.back();

  short_positions.pop_back();
  pos.close_price = last_ticks.get(0).ask;
  pos.close_time = last_ticks.get(0).time;
  history.push_back(pos);

  gain += pos.gain();
  // printf("close SHORT %f -> %f (%+5.1f pips) gain: %+.1f\n", pos.open_price, pos.close_price, pos.pips(), gain);
}

