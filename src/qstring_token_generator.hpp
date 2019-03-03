//
// Created by drpsy on 17-Nov-18.
//

#ifndef BOOST_ASIO_NPCBOOK_QSTRING_TOKEN_GENERATOR_HPP
#define BOOST_ASIO_NPCBOOK_QSTRING_TOKEN_GENERATOR_HPP

#include <string>

class qstring_token_generator {
 public:
  using iterator = std::string::const_iterator;

  /**
   * Constructor
   * @param open_q Start marker character
   * @param close_q End marker character
   * @param esc_c Escape character
   * @param skip_empty Indicator whether to skip empty tokens
   */
  explicit qstring_token_generator(char open_q = '"', char close_q = '"', char esc_c = '\\', bool skip_empty = true);

  /**
   * Operator()
   * @param next Start of a section of a string in which it looks for the next token
   * @param end End of the section
   * @param token
   * @return
   */
  bool operator()(iterator &next, iterator end, std::string &token);

  /**
   * makes sure that the internal variables used to maintain parsing state are reset appropriately
   * for the parsing to restart
   */
  void reset();

 private:
  /**
   * Meant to be called each time we identify the beginning of a new token
   * @param next
   * @return
   */
  iterator start_token(iterator &next);

  /**
   * Meant to be called each time we identify the end of a token
   * @param next
   * @param token_start
   * @return Complete token as string
   */
  std::string end_token(iterator &next, iterator token_start);

  char start_marker;
  char end_marker;
  char escape_char;
  bool skip_empty_tokens;
  bool in_token;  // true while parsing content inside quotes
  bool in_escape; // true if the current character is part of an escape sequence
};

#endif //BOOST_ASIO_NPCBOOK_QSTRING_TOKEN_GENERATOR_HPP
