#include <string>
#include <boost/algorithm/string.hpp>
#include <iostream>

template<typename RangeT>
boost::iterator_range<typename boost::range_iterator<RangeT>::type> find_xdigit_token(RangeT &Input) {
  return boost::find_token(Input, boost::is_xdigit(), boost::token_compress_on);
}

int main() {
  std::string str = "The application tried to read from an invalid address at 0xbeeffed";
  boost::iterator_range<std::string::iterator> token = find_xdigit_token(str);

  while (token.begin() != token.end()) {
    if (boost::size(token) > 3) {
      std::cout << "\'" << token << "\' at position: " << token.begin() - str.begin() << '\n';
    }
    boost::iterator_range<std::string::iterator> remnant = boost::make_iterator_range(token.end(), str.end());
    token = find_xdigit_token(remnant);
  }

  return EXIT_SUCCESS;
}