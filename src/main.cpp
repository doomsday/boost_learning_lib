#include <string>
#include <boost/algorithm/string.hpp>
#include <cassert>

int main() {
  std::string input = "linearize";
  std::string test = "near";
  assert(boost::contains(input, test));

  return EXIT_SUCCESS;
}