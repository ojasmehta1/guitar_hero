#ifndef _RING_BUFFER_HPP
#define _RING_BUFFER_HPP

#include <stdint.h>
#include <vector>

class RingBuffer {
 public:
  explicit RingBuffer(int capacity);
  int Size() const;
  bool isEmpty() const;
  bool isFull() const;
  void enqueue(int16_t arg);
  int16_t dequeue();
  int16_t peek() const;
  void emptyBuffer();
private:
 std::vector<int16_t> buffer;
 int mySize;
 int myCapacity;
 int first;
 int last;
};

#endif
