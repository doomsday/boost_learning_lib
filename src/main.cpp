#include <string>
#include <boost/container/stable_vector.hpp>
#include <cassert>
#include <iostream>

/* What we want to show is that once we add elements beyond the capacity of the
 * stable_vector, requiring an expansion of the underlying array and movement of
 * the existing data, iterators computed before the change in capacity still remain valid */

int main() {

  const char *cloud_names[] = {"cumulus", "cirrus", "stratus", "cumulonimbus", "cirrostratus",
                               "cirrocumulus", "altocumulus", "altostratus"};

  boost::container::stable_vector<std::string> clouds;
  clouds.reserve(4);
  //clouds.resize(4); // To circumvent a bug in Boost 1.54

  size_t name_count = sizeof(cloud_names)/sizeof(const char*);
  size_t capacity = clouds.capacity();

  size_t i = 0;
  for (i = 0; i < name_count && i < capacity; ++i) {
    clouds.push_back(cloud_names[i]);
  }
  std::cout << "\n1 ===========\n";
  for (auto & cloud : clouds) {
    std::cout << "\"" << cloud << "\"\n";
  }

  auto first = clouds.begin();

  for (; i < name_count; ++i) {
    clouds.push_back(cloud_names[i]);
  }
  std::cout << "\n2 ===========\n";
  for (auto & cloud : clouds) {
    std::cout << "\"" << cloud << "\"\n";
  }

  auto sixth = clouds.begin() + 5;

  // 1 erase @4
  clouds.erase(clouds.begin() + 4);
  std::cout << "\n3 ===========\n";
  for (auto & cloud : clouds) {
    std::cout << "\"" << cloud << "\"\n";
  }
  // 2 inserts @3
  clouds.insert(clouds.begin() + 3, "stratocumulus");
  clouds.insert(clouds.begin() + 3, "nimbostratus");

  std::cout << "\n4 ===========\n";
  for (auto & cloud : clouds) {
    std::cout << "\"" << cloud << "\"\n";
  }

  assert(*first == cloud_names[0]);
  assert(sixth == clouds.begin() + 6);  // not +5
  assert(*sixth == cloud_names[5]);

  return EXIT_SUCCESS;

}