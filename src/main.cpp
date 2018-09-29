#include <string>
#include <iostream>
#include <cassert>
#include <boost/algorithm/string.hpp>

bool is_newline(char c) {
  return c == '\n';
}

int main() {

  std::string input = "  Hello  ";
  std::string input2 = "Hello   \n";

  std::string input_copy = boost::trim_copy(input);
  std::string input2_copy = boost::trim_right_copy_if(input2, is_newline);

  assert(*(input_copy.end() - 1) != ' ');
  assert(*(input2_copy.end() - 1) != '\n' && *(input2_copy.end() - 1) == ' ');

  return EXIT_SUCCESS;
}