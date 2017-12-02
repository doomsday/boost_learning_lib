//
// Boost.Optional: Accessing values stored in boost::optional.
//
#include <iostream>
#include <boost/variant.hpp>

#include "main.hpp"
#include "simple_variant_visitor.hpp"
#include "print_visitor.hpp"

int main() {

  boost::variant<Foo, int, std::string> value;  // Error if Foo not be default constructible.
  boost::variant<std::string, Foo, Bar> value2;

  // variant initialization and assignment should not result in an
  // ambiguity over which type to instantiate within the variant.

  value = 1;  // Sets int, not Foo.
  int *pi = boost::get<int>(&value);  // 'int' is the concrete type for the value we want.
  assert(pi != 0);

  // Overwriting the integer value stored earlier.
  value = Foo(42);

  // Overwriting the Foo value stored earlier.
  value = "foo";

  // value2 = 1 // Error: can be implicitly converted to Foo or Bar.

  // ====== Accessing values in a variant ======
  //
  boost::variant<std::string, int> v1;
  v1 = "19937";

  int i1;
  try {
    i1 = boost::get<int>(v1); // v1 stores a string at this point, this results in an exception being thrown.
  } catch (std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  int *pi1 = boost::get<int>(&v1); // Will return null.
  assert(pi1 == nullptr);

  // Get the zero-based index of the type of the value that is currently stored in the variant.
  size_t index = v1.which();  // Returns 0.

  // ====== Compile-time visitation ======
  //
  boost::variant<std::string, long, double> v3;
  v3 = 993.3773;
  boost::apply_visitor(simple_variant_visitor(), v3);

  // ====== Generic visitors ======
  //
  boost::apply_visitor(print_visitor(), v3);

  return EXIT_SUCCESS;
}

