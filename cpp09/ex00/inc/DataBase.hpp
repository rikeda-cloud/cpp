#ifndef CPP09_EX00_DataBase_H_
#define CPP09_EX00_DataBase_H_

#include <map>
#include <string>

class DataBase {
public:
  const double NOT_FOUND = -1.0;

  DataBase(void);
  ~DataBase(void);

  void insert(const std::string &, double);
  double select(const std::string &) const;

private:
  std::map<std::string, double> db_;

  DataBase(const DataBase &);
  DataBase &operator=(const DataBase &);
};

#endif
