#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <Eigen/Dense>
#include <boost/timer/timer.hpp>
#include <cstdlib>

using namespace boost::numeric::ublas;
using namespace Eigen;
using namespace boost::timer;

int main(int argc, char *argv[])
{	
	cpu_timer timer;
	float t_prev = 0., t_new;
	cpu_times times;


	for(int size = 0; size < atoi(argv[1]); size += atoi(argv[2]))
	{
		matrix <float> a(size, size);
		matrix <float> b(size, size);

		MatrixXf A = MatrixXf::Random(size, size);
		MatrixXf B = MatrixXf::Random(size, size);

		for ( unsigned i = 0; i < size; ++ i) {
			for ( unsigned j = 0; j < size; ++ j)
			{
				a(i, j) = A(i, j);
				b(i, j) = B(i, j);
			}
		}

		matrix <float> res(size, size);

		times = timer.elapsed();
		t_prev = times.user/1e9;

		res = prod(a,b);

		times = timer.elapsed();
		t_new = times.user/1e9;

		std::cout <<  size  << 'x' << size << ": " <<  t_new - t_prev << "sec" << std::endl;

	}
}

