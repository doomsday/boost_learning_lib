#include <string>
#include <iostream>
#include <vector>

#include <boost/algorithm/string.hpp>

int main() {

  try {

    std::string dogtypes = "mongrel, puppy, whelp, hound";
    std::vector<std::string> dogs;
    // token_compress_on - adjacent separators are merged together. Otherwise, every
    // two separators delimit a token
    boost::split(dogs, dogtypes, boost::is_any_of(" ,"), boost::token_compress_on);

    for(const std::string& dog : dogs) {
      std::cout << dog << '\n';
    }

  } catch (const std::exception &e) {
    std::cout << e.what();
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}