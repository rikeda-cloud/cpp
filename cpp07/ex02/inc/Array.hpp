#ifndef CPP07_EX02_Array_H_
# define CPP07_EX02_Array_H_

#include <cstddef>

template<class T> class Array {
public:
	Array(void) : array_(NULL) {}
	Array(unsigned int n, const T& v = T()) : array_size_(n) {
		array_ = new T[n];
		for (unsigned int i = 0; i < n; i++)
			array_[i] = v;
	}
	Array(const Array<T>& ary) {
		this->array_size_ = ary.array_size_;
		this->array_ = new T[ary.array_size_];
		for (size_t i = 0; i < array_size_; i++)
			this->array_[i] = ary.array_[i];

	}
	Array&	operator=(const Array<T>&);

	T		operator[](size_t idx) const;
	size_t	size(void) const;


private:
	T*		array_;
	size_t	array_size_;
};

#endif
