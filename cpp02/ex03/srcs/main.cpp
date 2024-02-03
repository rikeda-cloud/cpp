#include "Point.hpp"
#include <iostream>

int main( void ) {
	std::cout << bsp(Point(0, -1), Point(1, 1), Point(-1, 1), Point(0, 0)) << std::endl;
	std::cout << bsp(Point(0, -1), Point(1, 1), Point(-1, 1), Point(0, -1)) << std::endl;
	std::cout << bsp(Point(0, -1), Point(1, 1), Point(-1, 1), Point(0, 1)) << std::endl;
	std::cout << bsp(Point(0, -1), Point(1, 1), Point(-1, 1), Point(0, 0.99)) << std::endl;
	std::cout << bsp(Point(0, -1), Point(1, 1), Point(-1, 1), Point(0, -2)) << std::endl;
	return 0;
}
