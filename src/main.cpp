#include <iostream>
#include <boost/intrusive_ptr.hpp>
#include <boost/smart_ptr/intrusive_ref_counter.hpp>

namespace NS {
  class Bar : public boost::intrusive_ref_counter<Bar, boost::thread_safe_counter> {
   public:
    Bar() {}
    ~Bar() { std::cout << "~Bar invoked" << '\n'; }
  };
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

  assert(pi->use_count() == pi2->use_count() && pi2->use_count() == 2);
  std::cout << "pi->use_count() : " << pi->use_count() << '\n'
            << "pi2->use_count() : " << pi2->use_count() << '\n';

  return EXIT_SUCCESS;
}