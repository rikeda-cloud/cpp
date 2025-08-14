#ifndef CPP09_EX02_utils_H_
#define CPP09_EX02_utils_H_

#include "PairPointer.hpp"
#include <cstddef>

unsigned jacobsthal(unsigned);

std::size_t findInsertIdx(const std::vector<PairPointer> &, const PairPointer &,
                          std::size_t, std::size_t &);

#endif
