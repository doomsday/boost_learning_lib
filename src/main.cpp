#include <string>
#include <boost/algorithm/string.hpp>
#include <cassert>
#include <iostream>

int main() {
  const char *haystack = "Mary had a little lamb";
  const char *needles[] = {"little", "Little", nullptr};

  for (int i = 0; needles[i] != nullptr; ++i) {
    auto ret = boost::find_first(haystack, needles[i]);
//    auto ret = boost::find_nth(haystack, needles[i], 1);

    if (ret.begin() == ret.end()) {
      std::cout << "String [" << needles[i] << "] not found in"
                << " string [" << haystack << "]\n";
    } else {
      std::cout << "String [" << needles[i] << "] found at "
                << "offset " << ret.begin() - haystack
                << " in string [" << haystack << "]\n";
    }
  }

  return EXIT_SUCCESS;
}