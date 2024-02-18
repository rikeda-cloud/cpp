#include "Array.hpp"
// #include "Array.tpp"
#include <iostream>

int	main(void) {
	Array<int> ary(5);

	for (size_t i = 0; i < ary.size(); i++)
		ary[i] = i;
	try {
		std::cout << "size = " << ary.size() << std::endl;
		for (size_t i = 0; i < ary.size(); i++)
			std::cout << "array[" << i << "] = " << ary[i] << std::endl;
	}
	catch (std::exception& e){
		std::cerr << "raise index error" << std::endl;
	}

	return 0;
}

// 	__attribute__((destructor)) static void destructor()
// {
//    system("leaks -q Array");
// }
