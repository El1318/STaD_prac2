#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;

int main()
{
  Vector2d a(4,2);
  Matrix2d b;
  b << 5, -2,
       8, 4;
  Matrix2d c;
  c << -1, 2,
       0, 1;

  std::cout << b*a << std::endl;
  std::cout << b*c << std::endl;
  std::cout << b.colPivHouseholderQr().solve(a) << std::endl;
}