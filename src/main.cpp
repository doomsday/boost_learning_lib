#include <string>
#include <iostream>
#include <boost/container/slist.hpp>

int main() {

  using list_type = boost::container::slist<std::string>;
  using iter_type = list_type::iterator;

  list_type dinos;
  list_type::iterator last = dinos.before_begin();

  const char *dino_array [] = {"Elasmosaurus", "Fabrosaurus", "Galimimus", "Hadrosaurus", "Iguanodon", "Appatosaurus",
                               "Brachiosaurus", "Corythosaurus", "Dilophosaurus"};

  // fill the slist
  for (const char *period : dino_array) {
    dinos.emplace_after(last, period);
    ++last;
  }

  // find the pivot
  last = dinos.begin();
  iter_type iter = last;

  while(++iter != dinos.end()) {
    // lexically smallest string
    if (*last > *iter) {
      break;
    }
    ++last; // points to the element immediately before iter
  }

  // find the end of the tail
  auto itend = last;
  while (iter != dinos.end()) {
    ++itend;  // points to the last element in the list
    ++iter;
  }

  // splice after
  dinos.splice_after(dinos.before_begin(), dinos, last, itend);
  for (const auto& str: dinos){
    std::cout << str << '\n';
  }

  return EXIT_SUCCESS;

}