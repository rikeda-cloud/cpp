#include "DataBase.hpp"

const double DataBase::NOT_FOUND = -1.0;

DataBase::DataBase(void) : db_() {}

DataBase::~DataBase(void) {}

void DataBase::insert(const std::string &key, double value) {
  // INFO 重複する場合は上書き
  db_[key] = value;
}

double DataBase::select(const std::string &key) const {
  // INFO key以上の値の要素を指すイテレータを返す
  std::map<std::string, double>::const_iterator it = this->db_.lower_bound(key);

  // イテレータが探していた日付を指している場合はその値を返す
  if (it != db_.end() && it->first == key) {
    return it->second;
  }

  // keyがDB内の最小値よりも大きい場合、イテレータの一つ前の要素の値を返す
  if (it != db_.begin()) {
    --it;
    return it->second;
  }
  return NOT_FOUND;
}
