#ifndef CPP09_EX00_DataBase_H_
#define CPP09_EX00_DataBase_H_

#include <map>
#include <string>

class DataBase {
public:
  static const double NOT_FOUND;

  DataBase(void);
  ~DataBase(void);

  void insert(const std::string &, double);
  double select(const std::string &) const;

  /*
   * INFO パース成功時、引数で渡されたDBに値を詰める
   * WARN パース失敗時、std::exceptionをthrow
   */
  static void parseCsv(const std::string &, DataBase &);

private:
  std::map<std::string, double> db_;

  DataBase(const DataBase &);
  DataBase &operator=(const DataBase &);
};

#endif
