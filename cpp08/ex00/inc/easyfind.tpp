#include <exception>

template<class T> int	easyfind(const T& container, int value) {
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it) {
		if (*it == value)
			return *it;
	}
	throw std::exception();
}
