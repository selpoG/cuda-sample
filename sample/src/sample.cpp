#include <boost/version.hpp>
#include <iostream>
#include "sample.h"

auto bar(int a)
{
	std::cout << "hello " << a << std::endl;
	std::cout << "boostバージョン:" << BOOST_VERSION << std::endl;
	std::cout << "boostライブラリバージョン:" << BOOST_LIB_VERSION << std::endl;
	return a + 2;
}

int fuga(int a) { return bar(a); }
