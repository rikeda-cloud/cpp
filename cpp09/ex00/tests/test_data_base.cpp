#include "DataBase.hpp"
#include "test.hpp"
#include <iostream>

static bool _test_simple_db(void) {
  DataBase db;
  db.insert("2000-01-01", 1);
  db.insert("2000-01-10", 10);
  db.insert("2000-01-31", 31);

  if (db.select("2000-01-01") != 1 || db.select("2000-01-10") != 10 ||
      db.select("2000-01-31") != 31) {
    std::cout << "[ERROR] _test_simple_db: equal case" << std::endl;
    return true;
  }

  if (db.select("1999-12-31") != DataBase::NOT_FOUND ||
      db.select("2000-01-02") != 1 || db.select("2000-01-30") != 10 ||
      db.select("2000-02-01") != 31) {
    std::cout << "[ERROR] _test_simple_db: not equal case" << std::endl;
    return true;
  }

  std::cout << "[OK]" << std::endl;
  return false;
}

static bool _test_empty_db(void) {
  DataBase db;

  if (db.select("2000-01-01") != DataBase::NOT_FOUND) {
    std::cout << "[ERROR] _test_empty_db: no empty" << std::endl;
    return true;
  }
  std::cout << "[OK]" << std::endl;
  return false;
}

static bool _test_insert_multiple_key(void) {
  DataBase db;
  db.insert("2000-01-01", 1);
  db.insert("2000-01-01", 10);
  db.insert("2000-01-01", 100);

  if (db.select("2000-01-01") != 100) {
    std::cout << "[ERROR] _test_insert_multiple_key: not overwritten"
              << std::endl;
    return true;
  }
  std::cout << "[OK]" << std::endl;
  return false;
}

int test_data_base(void) {
  int fail_count =
      _test_simple_db() + _test_empty_db() + _test_insert_multiple_key();
  return fail_count;
}
