#include <boost/algorithm/string_regex.hpp>
#include <iostream>
#include <string>
#include <vector>

int main() {

  using std::string;
  using std::cout;

  try {

    string line = "All the you touch";
    std::vector<string> words;
    boost::find_all_regex(words, line, boost::regex("\\w+"));

    string record = "Pigs on the Wing|Dogs| Pigs| Sheep";
    std::vector<string> fields;
    boost::split_regex(fields, record, boost::regex("[\\|]"));

    for (const auto& word: words) { cout << word << ","; }
    cout << std::endl;
    for (const auto& field: fields) { cout << field << ","; }

  } catch (const std::exception &e) {
    cout << e.what();
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}