#include <boost/regex.hpp>
#include <iostream>
#include <string>

int main() {

  using std::string;
  using std::cout;

  try {

    string haystack_str = "animal=Llama lives_in=Chile and is related_to=vicuna";
    boost::regex r3(R"((\w+)=(\w+))");
    int subindx[] = {2, 1}; // specifying the sub-expressions we are interested in
    boost::sregex_token_iterator tokit(haystack_str.begin(), haystack_str.end(), r3, subindx), tokend;

    while (tokit != tokend) {
      cout << *tokit++ << '\n';
    }
    cout << '\n';

  } catch (const std::exception &e) {
    cout << e.what();
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}