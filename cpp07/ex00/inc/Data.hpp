#ifndef CPP07_EX00_Data_H_
#define CPP07_EX00_Data_H_

#include <string>

class Data {
public:
  Data(int, int);
  ~Data(void);
  Data(const Data &);
  Data &operator=(const Data &);

  int getIncomparableV(void) const;

  bool operator>(const Data &) const;
  bool operator<(const Data &) const;
  bool operator>=(const Data &) const;
  bool operator<=(const Data &) const;
  bool operator==(const Data &) const;
  bool operator!=(const Data &) const;

private:
  int comparable_v_;
  int incomparable_v_;
};

#endif
