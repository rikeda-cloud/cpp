#ifndef CPP09_EX02_PairPointer_H_
#define CPP09_EX02_PairPointer_H_

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

private:
  unsigned val_;
  PairPointer *small_pair_;
  PairPointer *large_pair_;

  PairPointer(void);
};

#endif
