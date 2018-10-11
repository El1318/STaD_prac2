#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;

int main()
{
  Vector3d a(1,5,-2);
  Vector3d b(2,-2,4);
  std::cout << a.dot(b) << std::endl;
  std::cout << a.cross(b) << std::endl;
}