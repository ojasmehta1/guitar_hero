#include "RingBuffer.hpp"
#include <stdint.h>
#include <iostream>
#include <stdexcept>

RingBuffer::RingBuffer(int capacity) 
{
	
  try 
  {
    if (capacity < 1)
      throw std::invalid_argument("Capacity should be greater than 0");
  } 
  catch(std::invalid_argument& ia) 
  {
    std::cerr << "Capacity should be greater than 0.";
    std::cerr << std::endl;
    throw ia;
  }

  buffer.reserve(capacity);
  

  for (int i = 0; i < capacity; i++)
  {
    buffer.push_back(0);
	}
    first = 0;
    last = 0;
    mySize = 0;
    myCapacity = capacity;
  
}

bool RingBuffer::isFull() const 
{
  return mySize < myCapacity ? false : true;
}

bool RingBuffer::isEmpty() const 
{
  return mySize > 0 ? false : true;
}
int RingBuffer::Size() const 
{
  return mySize;
}

void RingBuffer::emptyBuffer() {
  first = 0;
  last = 0;
  mySize = 0;
}

void RingBuffer::enqueue(int16_t input) 
{
  try {
    if (isFull())
      throw std::runtime_error("Full Buffer");
  } 
  catch(std::runtime_error& runErr) 
  {
    std::cerr << "Full Buffer" << std::endl;
    throw runErr;
  }

  buffer[last] = input;

  if (last == myCapacity - 1)
    last = 0;
  else
    last++;

  mySize++;
}

int16_t RingBuffer::dequeue() 
{
  try {
    if (isEmpty())
      throw std::runtime_error("Full Buffer");
  } 
  catch(std::runtime_error& runErr) 
  {
    std::cerr << "Buffer Empty" << std::endl;
    throw runErr;
  }

  int16_t temp = peek();

  if (first == myCapacity - 1)
  {
    first = 0;
}
  else
  {
    first++;
}
  mySize--;

  return temp;
}

int16_t RingBuffer::peek() const 
{
  try 
  {
    if (isEmpty())
      throw std::runtime_error("Buffer Empty");
  } 
  catch(std::runtime_error& re) 
  {
    std::cerr << "Buffer Empty" << std::endl;
    throw re;
  }

  return buffer[first];
}


