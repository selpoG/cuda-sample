#include <boost/version.hpp>
#include <iostream>
#include <memory>
#include "sample.h"

int main()
{
	auto annealer = std::make_unique<Annealer>();
	std::cout << fuga(3) << std::endl;
	std::cout << annealer.get()->hoge(3) << std::endl;
	std::cout << "boostバージョン:" << BOOST_VERSION << std::endl;
	std::cout << "boostライブラリバージョン:" << BOOST_LIB_VERSION << std::endl;
	return 0;
}
