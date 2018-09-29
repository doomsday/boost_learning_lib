#include <string>
#include <boost/algorithm/string.hpp>
#include <boost/range/adaptors.hpp>
#include <iostream>

int main() {
  std::string str = "funny text";
  std::string str2(str);
  // strided adaptor that allows traversing the range by skipping a fxed number of elements at each step
  auto range = str | boost::adaptors::strided(2); // strided operator |
  auto range2 = str2 | boost::adaptors::sliced(1, str2.size() - 1)
                     | boost::adaptors::strided(2);

  boost::to_upper(range);
  boost::to_upper(range2);

  std::cout << str << '\n'; // FuNnY TeXt
  std::cout << str2 << '\n';  // fUnNy tExt

  return EXIT_SUCCESS;
}