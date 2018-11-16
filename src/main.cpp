#include <string>
#include <iostream>

#include <boost/tokenizer.hpp>

int main() {

  /**
   * Tokenizing records with fields containing metacharacters.
   */

  using std::string;

  try {

    string input = R"(Amit Gupta,70,\"Nandanvan\",Ghole Road,Pune,India)";
    using tokenizer = boost::tokenizer<boost::escaped_list_separator<string::value_type>>;
    tokenizer my_tokenizer(input);

    for (const string& tok : my_tokenizer) {
      std::cout << tok << '\n';
    }

  } catch (const std::exception &e) {
    std::cout << e.what();
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}