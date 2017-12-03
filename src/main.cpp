#include <iostream>
#include <boost/lexical_cast.hpp>

using std::string;
using std::cout;
using std::endl;

int main() {

  // lexical_cast.
  string str = "1234";
  try {
    auto n = boost::lexical_cast<int>(str);
    assert(n == 1234);
  } catch (boost::bad_lexical_cast& e) {
    cout << e.what() << endl;
  }

  return EXIT_SUCCESS;
}

