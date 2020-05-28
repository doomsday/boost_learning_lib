#include <boost/regex.hpp>
#include <string>
#include <iostream>

int main() {

  using std::string;
  using std::cout;

  try {

    string haystack_str = "An array of papers from the academia on Alaska area's fauna";
    boost::regex r2("a\\w*a");
    boost::smatch matches;
    string::const_iterator start = haystack_str.begin(), end = haystack_str.end();

    while (boost::regex_search(start, end, matches, r2)) {
      cout << "Matched substring " << matches.str()
                << " at offset " << matches[0].first - haystack_str.begin()
                << " of length " << matches[0].length() << '\n';
      start = matches[0].second;  // set the start iterator to the first location past the end of the last match
    }

  } catch (const std::exception &e) {
    cout << e.what();
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}