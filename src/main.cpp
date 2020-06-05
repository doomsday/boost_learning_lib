#include <boost/regex.hpp>
#include <cassert>
#include <iostream>

int main() {

  try {

    std::string str4 = "England's Queen, India's President, people's choice";
    boost::regex r4(R"((\w+)'s\s+(\w+))");
    std::string rep = boost::regex_replace(str4, r4, R"(\2 of \1)");
    assert(rep == "Queen of England, President of India, choice of people");

  } catch (const std::exception &e) {
    std::cout << e.what();
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}