#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;

int main()
{
  Matrix2d a;
  a << 1, 2,
       3, 4;
  MatrixXd b(2,2);
  b(0,0) = 4;
  b(1,0) = 6;
  b(0,1) = -2;
  b(1,1) = 1;
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << a+b << std::endl;
}