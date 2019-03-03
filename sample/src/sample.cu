#include <boost/version.hpp>
#include <iostream>
#include "sample.h"
#include "cuda_utility.h"

constexpr unsigned N = 15;

__global__ void hello(int a) { printf("hello from GPU! %d (%d\n", a, N); }

int Annealer::hoge(int a)
{
	CALL_KERNEL(hello, 3, 4)(a);
	CHECK_CUDA_ERROR(cudaDeviceSynchronize());
	std::cout << "hello " << a << std::endl;
	std::cout << "boostバージョン:" << BOOST_VERSION << std::endl;
	std::cout << "boostライブラリバージョン:" << BOOST_LIB_VERSION << std::endl;
	return a + 1;
}
