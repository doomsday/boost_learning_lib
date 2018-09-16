#include <string>
#include <boost/algorithm/string.hpp>
#include <iostream>
#include <vector>

struct min_len {
  bool operator()(const std::string& s) const {
    return s.size() > 3;
  }
};

int main() {
  std::string str = "The application tried to read from an invalid address at 0xbeeffed";

  std::vector<std::string> v;
  auto ret = boost::iter_find(v, str, boost::token_finder(boost::is_xdigit(), boost::token_compress_on));

  std::ostream_iterator<std::string> osit(std::cout, ", ");
  std::copy_if(v.begin(), v.end(), osit, min_len());

  return EXIT_SUCCESS;
}