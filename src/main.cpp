#include <string>
#include <iostream>
#include <vector>

#include <boost/algorithm/string.hpp>

int main() {

  try {

    /**
     * boost::join and boost::join_if algorithms are pretty useful when you are
     * trying to string together a sequence of values with some separator between
     * successive values.
     */

    std::vector<std::string> vec {"mongrel", "puppy", "whelp", "hound"};
    std::cout << boost::join(vec, ", ");

  } catch (const std::exception &e) {
    std::cout << e.what();
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}