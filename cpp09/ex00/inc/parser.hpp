#ifndef CPP09_EX00_parser_H_
#define CPP09_EX00_parser_H_

#include "DataBase.hpp"
#include <string>

/*
 * INFO パース成功時、引数で渡されたDBに値を詰める
 * WARN パース失敗時、std::exceptionをthrow
 */
void parseCsv(const std::string &, DataBase &);

/*
 * INFO パース成功時、引数で渡された参照に値を詰める
 * WARN パース失敗時、std::exceptionをthrow
 */
bool parseLine(const std::string &line, const std::string &sep,
               std::string &key, double &value);

bool validateBtcDate(const std::string &);
bool valiadteValue(const std::string &);
bool isDate(int, int, int);

#endif
