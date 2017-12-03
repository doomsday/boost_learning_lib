#include <iostream>
#include <boost/any.hpp>
#include <cassert>

class my_value {
  int value;
 public:
  explicit my_value(int i) : value(i) {}
  int get() const { return value; }
};

int main() {

  using boost::any_cast;
  using std::cout;
  using std::endl;
  using boost::any;

  // Basic usage.
  any
      v1, v2, v3, v4;

  assert(v1.empty());
  const char *hello = "Hello";
  v1 = hello;
  v2 = 42;
  v3 = std::string("Hola");
  my_value m1(10);
  v4 = m1;

  try {
    cout << any_cast<const char*>(v1) << endl;
    cout << any_cast<int>(v2) << endl;
    cout << any_cast<std::string>(v3) << endl;
    auto x = any_cast<my_value>(v4);
    cout << x.get() << endl;
  } catch (std::exception& e) {
    cout << e.what() << endl;
  }

  // Swapping value.
  any v5 = 19937;
  any v6 = std::string("Hello");

  assert(any_cast<int>(&v5) != nullptr);
  assert(any_cast<std::string>(&v6) != nullptr);

  v5 = 22.36;
  v5.swap(v6);

  assert(any_cast<std::string>(&v5) != nullptr);
  assert(any_cast<double>(&v6) != nullptr);

  // Accessing type information (needs RTTI).
  any value = 20;
  if (value.type().hash_code() == typeid(int).hash_code()) {
    cout << any_cast<int>(value) << endl;
  }

  return EXIT_SUCCESS;
}

