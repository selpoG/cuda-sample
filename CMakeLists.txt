cmake_minimum_required(VERSION 3.13.0)
project(sample)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)

if(MSVC)
	string(REPLACE "/W3" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
else()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Weffc++ -O3")
endif()

find_package(Boost 1.69.0)

add_subdirectory(sample)
add_subdirectory(main)

set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT main)
