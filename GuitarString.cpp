#include <cmath>
#include "GuitarString.hpp"
#include "RingBuffer.hpp"

GuitarString::GuitarString(double frequency) : buffer(ceil(44100/frequency)) 
{
  count = 0;
}

GuitarString::GuitarString(std::vector<int16_t> vc) : buffer(vc.size()) 
{
  for (unsigned i = 0; i < vc.size(); i++)
  {
    buffer.enqueue(vc[i]);
}
  count = 0;
}

void GuitarString::pluck() 
{
  buffer.emptyBuffer();

  while (!buffer.isFull())
  {
    buffer.enqueue((int16_t)(rand() & 0xffff));
	}
}

void GuitarString::tic() 
{
  int n1 = buffer.dequeue();
  int n2 = buffer.peek();

  buffer.enqueue(0.5 * 0.996 * (n1 + n2));

  count++;
}

int GuitarString::time() const 
{
  return count;
}

int16_t GuitarString::sample() const 
{
  return buffer.peek();
}

