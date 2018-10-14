#define BOOST_TEST_MODULE test4
#include <boost/test/unit_test.hpp>
#include <iostream>
#include <Eigen/Dense>
#include <Eigen/Eigenvalues>

using namespace Eigen;

BOOST_AUTO_TEST_CASE( success_test )
{
  Matrix3d a;
  a << 5,0,0,
  	   0,4,0,
  	   0,0,3;

  EigenSolver<Matrix3d> s(a, false);

  int det = 60;
  Matrix3d inv;
  inv << 1./5,0,0,
  	   0,1./4,0,
  	   0,0,1./3;
  
  BOOST_CHECK( a.determinant() == det );
  BOOST_CHECK( a.inverse() == inv );
}