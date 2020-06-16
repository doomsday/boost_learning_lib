#include <string>
#include <iostream>
#include <boost/container/slist.hpp>

int main() {

  boost::container::slist<std::string> eras;
  boost::container::slist<std::string>::iterator last = eras.before_begin();

  const char *era_names [] = {"Cambrian", "Ordovician", "Silurian", "Devonian", "Carboniferous", "Silurian",
                              "Devonian", "Carboniferous", "Cretaceous", "Paleogene", "Neogene"};

  for (const char *period : era_names) {
    eras.emplace_after(last, period);
    ++last;
  }

  for (const std::string& era : eras) {
    std::cout << era << '\n';
  }

  return EXIT_SUCCESS;

}