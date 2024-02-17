#include "iter.hpp"
#include <iostream>

template<class T> void	print_array(T& array, size_t length) {
	for (size_t i = 0; i < length; i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
}

template<class T> void	valueX2(T *value) {
	*value *= 2;
}

template<> void	valueX2(char *value) {
	*value += 2;
}

void	toUpper(char *c) {
	if (islower(*c))
		*c = toupper(*c);
}

template<class T> void	try_iter(T* array, size_t length, void (*f)(T *val)) {
	std::cout << "length: " << length << std::endl;
	std::cout << "before: ";
	print_array(array, length);
	iter(array, length, f);
	std::cout << "after : ";
	print_array(array, length);
}

int	main(void) {
	int		int_array[5] = {1,2,3,4,5};
	char	char_array[] = "abcde";
	float	float_array[5] = {1.1, 2.2, 3.3, 4.4, 5.5};

	try_iter(int_array, 5, valueX2);
	try_iter(char_array, 5, valueX2);
	try_iter(float_array, 5, valueX2);
	
	return 0;
}
