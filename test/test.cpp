// #define BOOST_TEST_MODULE First_TestSuite
// #include <boost/test/included/unit_test.hpp>

#define BOOST_TEST_MODULE example
#include <boost/test/included/unit_test.hpp>
#include <iostream>

BOOST_AUTO_TEST_CASE(wut)
{
    std::cout << "Testing...";
    BOOST_TEST(true);
}