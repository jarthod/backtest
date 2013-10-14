#include <string>

using namespace std;

template <class T>
class CircularBuffer
{
  public:

    CircularBuffer(unsigned size = 100)
    {
      this->size = size;
      this->next_slot = 0;
      buffer = new T[size];
    };

    ~CircularBuffer()
    {
      delete[] buffer;
    };

    void  insert(const T& value)
    {
      buffer[next_slot] = value;
      ++next_slot;
      if (next_slot >= size)
        next_slot = 0;
    };

    const T&  get(unsigned lookback = 0) const
    {
      int index = (next_slot - 1 - lookback + size) % size;
      return buffer[index];
    };

  private:

    T*        buffer;
    unsigned  next_slot;
    unsigned  size;
};
