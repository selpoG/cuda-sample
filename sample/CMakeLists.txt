cmake_minimum_required(VERSION 3.13.0)

find_package(CUDA REQUIRED)
if(CUDA_FOUND)
	set(MY_TARGET sample)
	if(MSVC)
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4819")
	else()
		set(CUDA_NVCC_FLAGS "${CUDA_NVCC_FLAGS} --std=c++14")
	endif()
	set(CUDA_NVCC_FLAGS "${CUDA_NVCC_FLAGS} -gencode arch=compute_61,code=sm_61")
	set(CUDA_NVCC_FLAGS_DEBUG "${CUDA_NVCC_FLAGS_DEBUG} -O0 -G -g")
	set(CUDA_NVCC_FLAGS_RELEASE "${CUDA_NVCC_FLAGS_RELEASE} -lineinfo")
	file(GLOB SOURCES "src/*.cu" "src/*.cpp" "src/*.c")
	file(GLOB HEADERS "include/*.cuh" "include/*.hpp" "include/*.h")
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ../bin)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ../bin)
	set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ../lib)
	set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ../lib)
	set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ../lib)
	set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../lib)
	set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ../lib)
	set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ../lib)
	CUDA_ADD_LIBRARY(${MY_TARGET} STATIC ${SOURCES} ${HEADERS})
	set_target_properties(
		${MY_TARGET} PROPERTIES
		OUTPUT_NAME_DEBUG ${MY_TARGET}-debug
		OUTPUT_NAME_RELEASE ${MY_TARGET}
	)
	target_include_directories(${MY_TARGET} PUBLIC
		"${Boost_INCLUDE_DIRS}"
		include
	)
endif()
