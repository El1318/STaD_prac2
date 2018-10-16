#include <iostream>
#include <Eigen/Dense>
#include <boost/timer/timer.hpp>
#include <cstdlib>

using namespace Eigen ;
using namespace boost::timer;

MatrixXf rand_mul(int size)
{
	MatrixXf A = MatrixXf::Random(size, size);
	MatrixXf B = MatrixXf::Random(size, size);

	return A*B;
}


int main(int argc, char *argv[])
{
	cpu_timer timer;
	MatrixXf mul;

	for(int i = 0; i < atoi(argv[1]); i += atoi(argv[2]))
	{
		mul = rand_mul(i);
		cpu_times times = timer.elapsed();
		std::cout <<  i << 'x' << i << ": " <<  times.wall/1e9 << "sec" << std::endl;
	}

	return 0;
}