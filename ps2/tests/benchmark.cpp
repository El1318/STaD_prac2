#include <iostream>
#include <Eigen/Dense>
#include <boost/timer/timer.hpp>
#include <cstdlib>

using namespace Eigen;
using namespace boost::timer;


int main(int argc, char *argv[])
{
	cpu_timer timer;
	float t_prev = 0., t_new;
	cpu_times times;
	MatrixXf mul;

	for(int size = 0; size < atoi(argv[1]); size += atoi(argv[2]))
	{
		MatrixXf A = MatrixXf::Random(size, size);
		MatrixXf B = MatrixXf::Random(size, size);
		MatrixXf res = MatrixXf::Random(size, size);

		times = timer.elapsed();
		t_prev = times.user/1e9;

		res =  A*B;

		times = timer.elapsed();
		t_new = times.user/1e9;

		std::cout <<  size << 'x' << size << ": " <<  t_new - t_prev << "sec" << std::endl;
		t_prev = t_new;
	}

	return 0;
}