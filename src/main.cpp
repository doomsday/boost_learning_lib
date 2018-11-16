#include <string>
#include <iostream>

#include <boost/tokenizer.hpp>

int main() {

  using std::string;

  try {

    string input = R"(201408091403290000001881303614419ABNANL2AWSSDEUTDEMM720000000412000EUR)";
    int lengths[] = {8, 9, 16, 11, 11, 12, 13};

    boost::offset_separator ofs(lengths, lengths + 7);
    using tokenizer = boost::tokenizer<boost::offset_separator>;
    tokenizer my_tokenizer(input, ofs);

    for (const string& tok : my_tokenizer) {
      std::cout << tok << '\n';
    }

  } catch (const std::exception &e) {
    std::cout << e.what();
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}