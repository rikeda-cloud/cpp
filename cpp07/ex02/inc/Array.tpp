#ifndef CPP07_EX02_Array_TPP_
#define CPP07_EX02_Array_TPP_

#include <exception>
#include <cstddef>

template <typename T>
Array<T>::Array(void) : array_(NULL), size_(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : size_(n) {
	array_ = new T[n]();
}

template <typename T>
Array<T>::~Array(void) {
	delete[] array_;
}

template <typename T>
Array<T>::Array(const Array<T> &arr) : size_(arr.size_) {
	this->array_ = new T[arr.size_]();
	for (unsigned int i = 0; i < arr.size_; ++i) {
		this->array_[i] = arr.array_[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T> &arr) {
	if (this != &arr) {
		if (this->size_) {
			delete[] this->array_;
		}
		this->size_ = arr.size_;
		this->array_ = new T[arr.size_]();
		for (unsigned int i = 0; i < arr.size_; ++i) {
			this->array_[i] = arr.array_[i];
		}
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int idx) {
	if (this->size_ <= idx) {
		throw std::exception();
	}
	return this->array_[idx];
}

template <typename T>
const T& Array<T>::operator[](unsigned int idx) const {
	if (this->size_ <= idx) {
		throw std::exception();
	}
	return this->array_[idx];
}

template <typename T>
unsigned int Array<T>::size(void) const {
	return this->size_;
}

#endif
