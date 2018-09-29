#include <string>
#include <iostream>

#include <boost/tokenizer.hpp>

int main() {

  using std::string;

  try {

    string input = "God knows, I've never been a spiritual man!";
    boost::tokenizer<> tokenized(input);

    /*
     * Default tokenizing policy splits the string using whitespace and punctuation
     * as token delimiters or separators. */
    for(const string & token : tokenized) {
      std::cout << token << '\n';
    }

    std::cout << '\n' << "******************" << "\n\n";

    /*
     * Split the input based on spaces and punctuation but not split on an apostrophe */
    boost::char_separator<string::value_type> sep(" \t,.!?;./\"(){}[]<>");  // construct the splitting policy
    using tokenizer = boost::tokenizer<boost::char_separator<char>>;
    tokenizer my_tokenizer(input, sep);
    for (const string & token : my_tokenizer) {
      std::cout << token << '\n';
    }

  } catch (const std::exception &e) {
    std::cout << e.what();
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}