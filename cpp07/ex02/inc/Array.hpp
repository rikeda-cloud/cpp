#ifndef CPP07_EX02_Array_H_
# define CPP07_EX02_Array_H_

#include <cstddef>

template<class T> class Array {
public:
	Array(void);
	Array(unsigned int n, const T& v = T());
	Array(const Array<T>& ary);
	Array&	operator=(const Array<T>& ary);
	T&		operator[](size_t idx) const;
	size_t	size(void) const;

private:
	T*		array_;
	size_t	array_size_;
};

#include "Array.tpp"

#endif
