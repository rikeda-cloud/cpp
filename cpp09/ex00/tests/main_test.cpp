#include "test.hpp"

int main(void) {
  return test_exchange() + test_data_base() + test_parse_csv() +
         test_validate_btc_date() + test_validate_value() + test_is_date() +
         test_parse_line();
}
