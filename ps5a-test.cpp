#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main

#include <boost/test/unit_test.hpp>
#include <iostream>
#include <stdexcept>
#include "RingBuffer.hpp"

BOOST_AUTO_TEST_CASE(Enqueue_and_Dequeue) {
  BOOST_REQUIRE_THROW(RingBuffer test1(0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(test2) {
  RingBuffer test2(3);

  test2.enqueue(5);
  test2.enqueue(4);
  test2.enqueue(3);
  BOOST_REQUIRE(test2.peek() == 5);
  BOOST_REQUIRE_THROW(test2.enqueue(5), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(test3) {
  RingBuffer test3(7);

  test3.enqueue(3);
  BOOST_REQUIRE(test3.dequeue() == 3);
  BOOST_REQUIRE_THROW(test3.dequeue(), std::runtime_error);
}
