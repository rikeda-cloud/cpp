#ifndef CPP08_EX00_test_H_
#define CPP08_EX00_test_H_

#include <string>

template <typename T>
bool test_container(const T &container, const std::string &container_type,
                    int p, bool expect_find);

#include "test.tpp"

#endif
