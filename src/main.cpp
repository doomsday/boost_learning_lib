#include <string>
#include <iostream>
#include <vector>

#include <boost/algorithm/string.hpp>

bool five_or_less_chars(const std::string& s) { return s.size() <= 5; }

int main() {

  try {

    /**
     * boost::join and boost::join_if algorithms are pretty useful when you are
     * trying to string together a sequence of values with some separator between
     * successive values.
     */

    std::vector<std::string> vec {"mongrel", "puppy", "whelp", "hound"};
    std::cout << boost::join_if(vec, ", ", five_or_less_chars);

  } catch (const std::exception &e) {
    std::cout << e.what();
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}