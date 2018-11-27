#define BOOST_TEST_MODULE test3
#include <boost/test/unit_test.hpp>
#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;

BOOST_AUTO_TEST_CASE( success_test )
{
  Vector2d a(4,2);
  Matrix2d b;
  b << 5, -2,
       8, 4;
  Matrix2d c;
  c << -1, 2,
       0, 1;

  Vector2d ba(16,40);
  Matrix2d bc;
  bc << -5, 8,
        -8, 20;
  
  BOOST_CHECK( b*a == ba );
  BOOST_CHECK( b*c == bc );
}