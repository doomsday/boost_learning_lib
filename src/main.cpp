#include <iostream>
#include <boost/intrusive_ptr.hpp>

namespace NS {
  class Bar {
   public:
    Bar() : refcount_(0) {}
    ~Bar() { std::cout << "~Bar invoked" << '\n'; }

    friend void intrusive_ptr_add_ref(Bar *);
    friend void intrusive_ptr_release(Bar *);

   private:
    unsigned long refcount_;

  };

  void intrusive_ptr_add_ref(Bar *b) {
    b->refcount_++;
  }

  void intrusive_ptr_release(Bar *b) {
    if (--b->refcount_ == 0) {
      delete b;
    }
  }

} // end NS

int main() {

  // Wrap dynamically-allocated objects. Pass true for the Boolean second
  // argument so that the intrusive_ptr constructor increments Bar's refcount_
  // through a call to intrusive_ptr_add_ref(NS::Bar*)
  boost::intrusive_ptr<NS::Bar> pi(new NS::Bar, true);
  boost::intrusive_ptr<NS::Bar> pi2(pi);

  assert(pi.get() == pi2.get());
  std::cout << "pi : " << pi.get() << '\n'
            << "pi2: " << pi2.get() << '\n';

  return EXIT_SUCCESS;
}