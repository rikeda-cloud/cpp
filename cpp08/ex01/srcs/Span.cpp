#include "Span.hpp"

Span::~Span(void) {}

Span::Span(unsigned int n) : capacity_(n) {}

Span::Span(const Span& span) :  vec_(span.vec_), capacity_(span.capacity_){}

Span&	Span::operator=(const Span& span) {
	if (this != &span) {
		this->capacity_ = span.capacity_;
		this->vec_ = span.vec_;
	}
	return *this;
}

void	Span::addNumber(int number) {
	if (capacity_ <= vec_.size())
		throw std::exception(); // 仮の例外クラス
	vec_.push_back(number);
}

void	Span::addNumber(std::vector<int> vector_to_concat) {
	vec_.insert(vec_.end(), vector_to_concat.begin(), vector_to_concat.end());
}

void	Span::addNumber(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end) {
	vec_.insert(vec_.end(), begin, end);
}

int	Span::shortestSpan(void) const {
	if (vec_.size() <= 1)
		throw std::exception(); // 仮の例外クラス
	int	shortest_span = std::abs(vec_[0] - vec_[1]);
	for (unsigned int i = 1; i < (vec_.size() - 1); i++) {
		int	span = std::abs(vec_[i] - vec_[i + 1]);
		if (span < shortest_span)
			shortest_span = span;
	}
	return shortest_span;
}

int	Span::longestSpan(void) const {
	if (vec_.size() <= 1)
		throw std::exception(); // 仮の例外クラス
	int	longest_span = std::abs(vec_[0] - vec_[1]);
	for (unsigned int i = 1; i < (vec_.size() - 1); i++) {
		int	span = std::abs(vec_[i] - vec_[i + 1]);
		if (longest_span < span)
			longest_span = span;
	}
	return longest_span;
}
