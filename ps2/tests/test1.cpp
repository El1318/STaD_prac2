#define BOOST_TEST_MODULE test1
#include <boost/test/unit_test.hpp>
#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;

BOOST_AUTO_TEST_CASE( success_test )
{
  Matrix2d a;
  a << 1, 2,
       3, 4;
  MatrixXd b(2,2);
  b(0,0) = 4;
  b(1,0) = 6;
  b(0,1) = -2;
  b(1,1) = 1;
  
  Matrix2d sum;
  sum << 5, 0,
         9, 5;  
    
  BOOST_CHECK( a+b == sum );

}