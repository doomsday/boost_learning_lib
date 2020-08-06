#include <boost/current_function.hpp>
#include <boost/container/static_vector.hpp>
#include <iostream>

/* boost::container::static_vector template is a vector-like container with an
 * upper limit on the size defined at compile time */

class chatty_init {
 public:
  chatty_init() {
    std::cout << BOOST_CURRENT_FUNCTION << '\n';
  }
};

int main() {

  boost::container::static_vector<chatty_init,10> myvector;
  std::cout << "boost::container::static_vector initialized" << '\n';
  while (myvector.size() < myvector.capacity()) {
    myvector.push_back(chatty_init());
  }

  // myvector.push_back(chatty_init()); // std::bad_alloc

  return EXIT_SUCCESS;

}