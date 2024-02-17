#ifndef CPP07_EX01_iter_H_
# define CPP07_EX01_iter_H_

#include <cstddef>

template<class T> void	iter(T *array, size_t length, void (*f)(T *val)) {
	for (size_t i = 0; i < length; i++)
		f(&array[i]);
}

#endif
