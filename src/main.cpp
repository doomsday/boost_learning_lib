#include <string>
#include <iostream>
#include <cassert>

#include <boost/algorithm/string.hpp>

int main() {

  try {

    std::string input = "Hello, World! Hello folks!";

    assert(boost::replace_first_copy(input, "Hello", "Hola") == "Hola, World! Hello folks!");
    assert(boost::erase_first_copy(input, " folks") == "Hello, World! Hello!");
    assert(boost::replace_head_copy(input, 5, "Hell") == "Hell, World! Hello folks!");

  } catch (const std::exception &e) {
    std::cout << e.what();
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}