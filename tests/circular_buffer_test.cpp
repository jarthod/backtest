#include <assert.h>
#include "circular_buffer.hpp"

int main()
{
  CircularBuffer<int> cb(3);

  // push item
  cb.insert(1);
  assert(cb.get(0) == 1);
  // push again
  cb.insert(2);
  assert(cb.get(0) == 2);
  assert(cb.get(1) == 1);
  // push again
  cb.insert(3);
  assert(cb.get(0) == 3);
  assert(cb.get(1) == 2);
  assert(cb.get(2) == 1);
  // cycles
  cb.insert(4);
  assert(cb.get(0) == 4);
  assert(cb.get(1) == 3);
  assert(cb.get(2) == 2);
}