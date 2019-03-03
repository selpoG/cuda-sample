#ifndef SAMPLE_CUDA_UTILITY_H_
#define SAMPLE_CUDA_UTILITY_H_

#include <cuda_runtime.h>
#include <cuda_runtime_api.h>
#include <iostream>
#include <memory>
#include <sstream>
#include <stdexcept>

namespace cuda
{
	inline void check_error(const ::cudaError_t e, const char* f, decltype(__LINE__) n)
	{
		if (e != ::cudaSuccess)
		{
			std::stringstream s;
			s << ::cudaGetErrorName(e) << " (" << e << ")@" << f << "#L" << n << ": " << ::cudaGetErrorString(e);
			throw std::runtime_error{s.str()};
		}
	}
}  // namespace cuda

#define CHECK_CUDA_ERROR(expr) (cuda::check_error(expr, __FILE__, __LINE__))

// 現行の GPU では, block あたりの thread 数は 1024 が上限
constexpr auto GPU_MAXTHREADS = 1024u;

#ifdef __INTELLISENSE__

#ifndef __CUDACC__
#define __CUDACC__
#endif

#include <cuda.h>
#include <cuda_runtime.h>
#include <cuda_runtime_api.h>
#include <device_functions.h>
#include <device_launch_parameters.h>

#define CALL_KERNEL(cuda_func, ...) cuda_func

#else

#define CALL_KERNEL(cuda_func, ...) cuda_func<<<__VA_ARGS__>>>

#endif

#endif
