#include <string>
#include <iostream>

#include <boost/tokenizer.hpp>

int main() {

  /**
   * Tokenizing records with fields containing metacharacters.
   */

  using std::string;

  try {

    string input = R"(/Alon Ben-Ari/-35-11~/5 Zamenhoff St., Tel Aviv)";
    // tilde (~) for escaping; hyphen (-) for field separator; forward slash (/) for quotes
    boost::escaped_list_separator<char> sep('~', '-', '/');
    using tokenizer = boost::tokenizer<boost::escaped_list_separator<string::value_type>>;
    tokenizer my_tokenizer(input, sep);

    for (const string& tok : my_tokenizer) {
      std::cout << tok << '\n';
    }

  } catch (const std::exception &e) {
    std::cout << e.what();
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}