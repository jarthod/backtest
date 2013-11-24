#include "position.hpp"

float Position::pips() const
{
  return (close_price - open_price) * type * 1000;
}

float Position::gain() const
{
  return (close_price - open_price) * type * lots * 100000;
}
