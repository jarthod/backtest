#include "strategy.hpp"

Strategy::Strategy()
{
  this->_gain = 0;
  this->spread = 1; // 1€ -> average kraken spread
  this->fee = 0.0026; // 0.26 % -> base taker kraken fee
  this->_name = "Strategy";
}

void  Strategy::new_tick(const Tick& tick)
{
  last_ticks.insert(tick);
  this->tick(tick);
}

float  Strategy::gain() const
{
  return _gain;
}

int  Strategy::trades() const
{
  return history.size();
}

const string& Strategy::name() const
{
  return _name;
}

void  Strategy::buy(float lots)
{
  Position pos;

  pos.type = Position::Type::LONG;
  pos.open_price = last_ticks.get(0).price + spread/2;
  pos.open_time = last_ticks.get(0).time;
  pos.lots = lots;
  pos.fee = this->fee;

  long_positions.push_back(pos);
}

void  Strategy::sell(float lots)
{
  Position pos;

  pos.type = Position::Type::SHORT;
  pos.open_price = last_ticks.get(0).price - spread/2;
  pos.open_time = last_ticks.get(0).time;
  pos.lots = lots;
  pos.fee = this->fee;

  short_positions.push_back(pos);
}

void Strategy::close_buy()
{
  Position pos = long_positions.back();

  long_positions.pop_back();
  pos.close_price = last_ticks.get(0).price - spread/2;
  pos.close_time = last_ticks.get(0).time;
  history.push_back(pos);

  _gain += pos.gain();
  // printf("close  LONG %f -> %f (%+5.1f) gain: %+.1f\n", pos.open_price, pos.close_price, pos.diff(), gain());
}

void Strategy::close_sell()
{
  Position pos = short_positions.back();

  short_positions.pop_back();
  pos.close_price = last_ticks.get(0).price + spread/2;
  pos.close_time = last_ticks.get(0).time;
  history.push_back(pos);

  _gain += pos.gain();
  // printf("close SHORT %f -> %f (%+5.1f) gain: %+.1f\n", pos.open_price, pos.close_price, pos.diff(), gain());
}

