#include <string>
#include <iostream>

#include <boost/tokenizer.hpp>
#include "qstring_token_generator.hpp"

int main() {

  using std::string;

  try {

    std::string input = "I'am taking a train from Frankfurt (am Main) to Frankfurt (an der Oder)";
    bool skip_empty = true;
    qstring_token_generator qsep('(', ')', '\\', skip_empty);
    using qtokenizer = boost::tokenizer<qstring_token_generator>;
    qtokenizer tokenizer(input, qsep);

    unsigned int n = 0;
    for (auto& token : tokenizer) {
      std::cout << ++n << ": " << token << '\n';
    }

  } catch (const std::exception &e) {
    std::cout << e.what();
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}