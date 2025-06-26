#include "Span.hpp"
#include <algorithm>
#include <limits>
#include <stdexcept>

Span::Span(unsigned int n) : n_(n), sorted_(false) {}

Span::~Span(void) {}

Span::Span(const Span &span)
    : n_(span.n_), vec_(span.vec_), sorted_(span.sorted_) {}

Span &Span::operator=(const Span &span) {
  if (this != &span) {
    this->n_ = span.n_;
    this->vec_ = span.vec_;
    this->sorted_ = span.sorted_;
  }
  return *this;
}

void Span::addNumber(int number) {
  if (vec_.size() >= n_) {
    throw std::length_error("Exceeded maximum size");
  }
  vec_.push_back(number);
  sorted_ = false;
}

unsigned int Span::shortestSpan(void) {
  prepareCalcSpan();
  unsigned int shortest = std::numeric_limits<unsigned int>::max();
  for (unsigned i = 1; i < vec_.size(); ++i) {
    unsigned int diff = calcDiff(vec_[i - 1], vec_[i]);
    if (diff < shortest) {
      shortest = diff;
    }
  }
  return shortest;
}

unsigned int Span::longestSpan(void) {
  prepareCalcSpan();
  return calcDiff(this->vec_.front(), this->vec_.back());
}

void Span::prepareCalcSpan(void) {
  /*
   * INFO 要素数の確認とソート
   */
  if (vec_.size() <= 1) {
    throw std::domain_error("Too few elements to compute difference.");
  }

  if (!sorted_) {
    std::sort(vec_.begin(), vec_.end());
    sorted_ = true;
  }
}

unsigned int Span::calcDiff(int v1, int v2) const {
  long long lv1 = static_cast<long long>(v1);
  long long lv2 = static_cast<long long>(v2);
  return (lv1 > lv2) ? lv1 - lv2 : lv2 - lv1;
}
