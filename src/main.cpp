#include <string>
#include <iostream>
#include <vector>
#include <cassert>

int main() {

  std::vector<int> v {1, 2, 3, 4, 5};
  auto first = v.begin();
  auto last = first + v.size() - 1;
  assert(*last == 5);
  v.insert(last, 4);  // inserting new element before the element at the specified position
  // *last = 10 // undefined behavior, invalid iterator
  for (int i = 0; i < 1000; ++i) {
    /* Even appending an element to the end of the vector could trigger a resize
     * of the vector's internal storage, requiring elements to be moved */
    v.push_back(i);
  }

  // *first = 0;  // likely invalidated

  return EXIT_SUCCESS;

}