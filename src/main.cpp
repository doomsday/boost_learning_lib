//
// Boost.Optional: Accessing values stored in boost::optional.
//

#include <tuple>
#include <vector>
#include <iostream>
#include <cassert>

#include "main.hpp"

int main() {

  // Create test data.
  std::vector<double> prices = get_test_data();

  // Access by element number.
  std::tuple<size_t, size_t, double> tuple = get_best_transact_days(prices);
  std::cout << "Tuple #0: " << std::get<0>(tuple) << std::endl;
  std::cout << "Tuple #1: " << std::get<1>(tuple) << std::endl;
  std::cout << "Tuple #2: " << std::get<2>(tuple) << std::endl;

  // Tie.
  size_t buyDay, sellDay;
  double profit;
  std::tie(buyDay, sellDay, profit) = get_best_transact_days(prices);

  // Comparing tuples (relational operators).
  std::tuple<int, int, std::string> t1 = std::make_tuple(1, 2, "Hello");
  std::tuple<double, double, const char*> t2 = std::make_tuple(1, 2, "Hell");
  assert(t1 > t2);

  // Writing generic code using tuples
  std::cout << "Tuple length: " << tuple_length(tuple);

  return EXIT_SUCCESS;
}