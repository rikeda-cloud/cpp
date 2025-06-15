#include "Span.hpp"
#include <cmath>
#include <limits>
#include <stdexcept>

Span::Span(unsigned int n)
    : n_(n), crr_idx_(0),
      shortest_span_(std::numeric_limits<unsigned int>::max()),
      longest_span_(0), array_(new int(n)) {}

Span::~Span(void) { delete this->array_; }

Span::Span(const Span &span)
    : n_(span.n_), crr_idx_(span.crr_idx_), shortest_span_(span.shortest_span_),
      longest_span_(span.longest_span_), array_(new int(span.n_)) {
  for (unsigned int i = 0; i < this->crr_idx_; ++i) {
    this->array_[i] = span.array_[i];
  }
}

Span &Span::operator=(const Span &span) {
  if (this != &span) {
    this->n_ = span.n_;
    this->crr_idx_ = span.crr_idx_;
    this->shortest_span_ = span.shortest_span_;
    this->longest_span_ = span.longest_span_;
    delete this->array_;
    this->array_ = new int(this->n_);
    for (unsigned int i = 0; i < this->crr_idx_; ++i) {
      this->array_[i] = span.array_[i];
    }
  }

  return *this;
}

void Span::addNumber(int number) {
  if (this->crr_idx_ >= this->n_) {
    throw std::length_error("Exceeded maximum size");
  }

  this->array_[this->crr_idx_] = number;
  this->crr_idx_++;

  if (this->crr_idx_ >= 2) {
    unsigned int diff = std::abs(this->array_[this->crr_idx_ - 2] -
                                 this->array_[this->crr_idx_ - 1]);
    if (diff < this->shortest_span_) {
      this->shortest_span_ = diff;
    }
    if (diff > this->longest_span_) {
      this->longest_span_ = diff;
    }
  }
}

unsigned int Span::shortestSpan(void) const {
  if (this->crr_idx_ <= 1) {
    throw std::domain_error("Too few elements to compute difference.");
  }
  return this->shortest_span_;
}

unsigned int Span::longestSpan(void) const {
  if (this->crr_idx_ <= 1) {
    throw std::domain_error("Too few elements to compute difference.");
  }
  return this->longest_span_;
}
