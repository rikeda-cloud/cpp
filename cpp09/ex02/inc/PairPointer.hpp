#ifndef CPP09_EX02_PairPointer_H_
#define CPP09_EX02_PairPointer_H_

#include <vector>

class PairPointer {
public:
  PairPointer(unsigned val, PairPointer *small_pair, PairPointer *large_pair);
  ~PairPointer(void);
  PairPointer(const PairPointer &);
  PairPointer &operator=(const PairPointer &);

  unsigned getVal(void) const;
  PairPointer *getSmallPair(void) const;
  PairPointer *getLargePair(void) const;

  bool operator>(const PairPointer &) const;
  bool operator<(const PairPointer &) const;
  bool operator>=(const PairPointer &) const;
  bool operator<=(const PairPointer &) const;
  bool operator==(const PairPointer &) const;
  bool operator!=(const PairPointer &) const;

  static std::vector<PairPointer> vecToPairVec(const std::vector<unsigned> &);
  static std::vector<unsigned> pairVecToVec(const std::vector<PairPointer> &);

private:
  unsigned val_;
  PairPointer *small_pair_;
  PairPointer *large_pair_;

  PairPointer(void);
};

#endif
