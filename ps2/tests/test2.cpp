#define BOOST_TEST_MODULE test2
#include <boost/test/unit_test.hpp>
#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;

BOOST_AUTO_TEST_CASE( success_test )
{
  Vector3d a(1,5,-2);
  Vector3d b(2,-2,4);

  int dot_product = -16;
  Vector3d cross_product(16, -8, -12);
  
  BOOST_CHECK( a.dot(b) == dot_product );
  BOOST_CHECK( a.cross(b) == cross_product );
}