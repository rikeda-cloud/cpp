#include <exception>

template<class T>
Array<T>::Array(void) : array_(NULL), array_size_(0) {}

template<class T>
Array<T>::Array(unsigned int n, const T& v) : array_size_(n) {
	array_ = new T[n];
	for (unsigned int i = 0; i < n; i++)
		array_[i] = v;
}

template<class T>
Array<T>::Array(const Array<T>& ary) : array_size_(ary.array_size_) {
	this->array_ = new T[ary.array_size_];
	for (size_t i = 0; i < array_size_; i++)
		this->array_[i] = ary.array_[i];
}

template<class T>
Array<T>&	Array<T>::operator=(const Array<T>& ary) {
	if (this != &ary) {
		if (this->array_size_)
			delete this->array_;
		this->array_size_ = ary.array_size_;
		this->array_ = new T[ary.array_size_];
		for (size_t i = 0; i < ary.array_size_; i++)
			this->array_[i] = ary.array_[i];
	}
	return *this;
}

template<class T>
T&		Array<T>::operator[](size_t idx) const {
	if (array_size_ == 0)
		throw std::exception();
	if (array_size_ <= idx)
		throw std::exception();
	return array_[idx];
}

template<class T>
size_t	Array<T>::size(void) const {
	return array_size_;
}
