#include <iostream>
#include <boost/lexical_cast.hpp>

using std::string;
using std::cout;
using std::endl;

namespace FoFum {
  class Foo {
   public:
    void bar() {
      cout << BOOST_CURRENT_FUNCTION << endl;
      bar_private(5);
    }

    static void bar_static() {
      cout << BOOST_CURRENT_FUNCTION << endl;
    }

   private:
    float bar_private(int x) const {
      cout << BOOST_CURRENT_FUNCTION << endl;
      return 0.0;
    }
  };
} // end namespace FoFum.

namespace {
  template <typename T>
  void baz(const T& x) {
    cout << BOOST_CURRENT_FUNCTION << endl;
  }
} // end unnamed namespace.

int main() {

  cout << BOOST_CURRENT_FUNCTION << endl;

  FoFum::Foo f;
  f.bar();
  FoFum::Foo::bar_static();
  baz(f);

  return EXIT_SUCCESS;
}

