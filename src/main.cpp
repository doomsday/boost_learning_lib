#include <boost/regex.hpp>
#include <string>
#include <iostream>

int main() {

  using std::string;
  using std::cout;

  try {

    string haystack_str = "An array of papers from the academia on Alaska area's fauna";
    boost::regex r2("a(\\w*)a");
    boost::smatch matches;
    string::const_iterator start = haystack_str.begin(), end = haystack_str.end();

    while (boost::regex_search(start, end, matches, r2)) {
      cout << "Matched substring [" << matches.str()
           << "] following [" << matches.prefix().str()
           << "] preceding [" << matches.suffix().str() << "]\n";
      start = matches[0].second;
      for (size_t s = 1; s < matches.size(); ++s) {
        if (matches[s].matched) {
          cout << "Matched substring [" << matches[s].str()
               << "] at offset " << matches[s].first - haystack_str.begin()
               << " of length " << matches[s].length() << '\n';
        }
      }
      cout << std::endl;
    }

  } catch (const std::exception &e) {
    cout << e.what();
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}