#include <string>
#include <iostream>
#include <vector>

#include <boost/algorithm/string.hpp>

int main() {

  try {

    /**
     * If you simply want to split a string using another string as a separator,
     * you may use boost::iter_split.
     */

    std::string dogtypes = "mongrel and puppy and whelp and hound";
    std::vector<std::string> dogs;

    boost::iter_split(dogs, dogtypes, boost::first_finder(" and "));

    for(const std::string& dog : dogs) {
      std::cout << dog << '\n';
    }

  } catch (const std::exception &e) {
    std::cout << e.what();
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}