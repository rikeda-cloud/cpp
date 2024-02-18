#include <vector>
#include <list>
#include <iostream>

// template<class Container>
// void	set(const Container& container) {
// 	int i = 0;
// 	for (const class Container::value_type& element : container) {
// 		element = i++;
// 	}
// 	std::cout << std::endl;
// }

template<typename T>
void	find(const T& container, int value) {
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it) {
		std::cout << *it << std::endl;
	}
	(void)value;
}

int	main(void) {
	std::vector<int>	v1(5);
	std::list<int>		v2(5);

	  find(v1, 1);
	  find(v2, 1);
	return 0;
}
