#include <iostream>
#include <memory>

#include <boost/current_function.hpp>
#include <cassert>

using std::cout;
using std::shared_ptr;
using std::make_shared;

class CanBeShared : public std::enable_shared_from_this<CanBeShared> {
 public:
  ~CanBeShared() {
    cout << BOOST_CURRENT_FUNCTION << '\n';
  }

  shared_ptr<CanBeShared> share() {
    return shared_from_this();
  }
};

typedef shared_ptr<CanBeShared> CanBeSharedPtr;

void doWork(CanBeShared& obj) {
  // second sharing
  CanBeSharedPtr sp = obj.share();
  cout << "Usage count in doWork " << sp.use_count() << '\n';
  assert(sp.use_count() == 2);
  assert(&obj == sp.get());

  // second sharing destroyed
}

int main() {
  // first sharing
  CanBeSharedPtr cbs = make_shared<CanBeShared>();
  doWork(*cbs.get());
  cout << cbs.use_count() << '\n';
  assert(cbs.use_count() == 1);

  return EXIT_SUCCESS;
}