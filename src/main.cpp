#include <string>
#include <boost/algorithm/string.hpp>
#include <cassert>
#include <iostream>

int main() {
  using string_range = boost::iterator_range<std::string::const_iterator>;

  std::vector<string_range> matches;
  std::string str = "He deserted the unit while they trudged through the desert one night.";

  boost::find_all(matches, str, "desert");
  for (auto match : matches) {
    std::cout << "Found [desert] at offset " << match.begin() - str.begin() << ".\n";
  }

  return EXIT_SUCCESS;
}