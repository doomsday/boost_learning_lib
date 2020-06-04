#include <boost/regex.hpp>
#include <iostream>
#include <string>

int main() {

  using std::string;
  using std::cout;

  try {

    string haystack_str = "An array of papers from the academia on Alaska area's fauna";
    boost::regex r1(R"(\ba\w*a\b)", boost::regex::icase);
    boost::sregex_iterator rit(haystack_str.begin(), haystack_str.end(), r1), rend;

    while (rit != rend) {
      cout << *rit++ << '\n';
    }

  } catch (const std::exception &e) {
    cout << e.what();
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}