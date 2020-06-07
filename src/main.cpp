#include <boost/container/vector.hpp>
#include <boost/foreach.hpp>
#include <cassert>
#include <iostream>

#include "String.hpp"

int main() {

  boost::container::vector<String> strVec;
  String world("world");
  // Move temporary (rvalue)
  strVec.push_back(String("Hello"));
  // Error, copy semantics needed
  //strVec.push_back(world);
  // Explicit move
  strVec.push_back(boost::move(world));
  // World nulled after move
  assert(world.get() == nullptr);
  // In-place construction
  strVec.emplace_back("Hujambo Dunia!");  // Swahili

  BOOST_FOREACH(auto& str, strVec) {
    std::cout << str.get() << '\n';
  }

  return EXIT_SUCCESS;
}