#include "position.hpp"

float Position::diff() const
{
  return (close_price - open_price) * type;
}

float Position::gain() const
{
  return diff() * lots - (abs(diff()) * lots * fee);
}
