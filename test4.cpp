#include <iostream>
#include <Eigen/Dense>
#include <Eigen/Eigenvalues>

using namespace Eigen;

int main()
{
  Matrix3d a;
  a << 5,1,-6,
  	   7,-1,1,
  	   2,-2,-5;
  EigenSolver<Matrix3d> s(a, false);
  std::cout << a.determinant() << std::endl;
  std::cout << a.inverse() << std::endl;
  std::cout << s.eigenvalues() << std::endl;
}