#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int	main(void) {
	std::vector<int>	v1(5);
	std::list<int>		v2(5);

	for (size_t i = 0; i < 5; i++)
		v1[i] = 5 - i;

	std::cout << easyfind(v1, 1) << std::endl;
	return 0;
}
