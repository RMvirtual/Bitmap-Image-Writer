#define BOOST_TEST_MODULE First_TestSuite
#include <boost/test/included/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_CASE(myTest)
{
    BOOST_CHECK(2 + 2 == 4);
    BOOST_CHECK(3 + 1 == 4);
}
