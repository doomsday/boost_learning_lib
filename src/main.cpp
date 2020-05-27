#include <boost/regex.hpp>
#include <string>
#include <cassert>
#include <iostream>

int main() {

  using std::string;

  try {

    std::string str1 = "Alaska area";
    boost::regex r1("a.*a");
    assert(!boost::regex_match(str1, r1));

  } catch (const std::exception &e) {
    std::cout << e.what();
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}