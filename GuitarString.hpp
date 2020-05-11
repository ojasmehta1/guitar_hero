#ifndef _GUITARSTRING_HPP
#define _GUITARSTRING_HPP

#include <stdint.h>
#include <vector>
#include "RingBuffer.hpp"

class GuitarString {
	
 private:
  RingBuffer buffer;
  int count;
  
 public:
  explicit GuitarString(double frequency);
  explicit GuitarString(std::vector<int16_t> init);
  void pluck();
  void tic();
  int16_t sample() const;
  int time() const;
};

#endif
