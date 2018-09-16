#include <string>
#include <boost/algorithm/string.hpp>
#include <iostream>
#include <vector>

template<typename RangeT, typename NeedleT>
boost::iterator_range<typename boost::range_iterator<RangeT>::type> find_xdigit_token(RangeT &input, NeedleT &needle) {
  return boost::find(input, boost::last_finder(needle, boost::is_iequal()));
}

int main() {
  std::string str = "How little is too little1", needle = "Little";
  boost::iterator_range<std::string::iterator> token = find_xdigit_token(str, needle);

  while (token.begin() != token.end()) {
    if (boost::size(token) > 3) {
      std::cout << "\'" << token << "\' at position: " << token.begin() - str.begin() << '\n';
    }
    boost::iterator_range<std::string::iterator> remnant = boost::make_iterator_range(token.end(), str.end());
    token = find_xdigit_token(remnant, needle);
  }

  return EXIT_SUCCESS;
}