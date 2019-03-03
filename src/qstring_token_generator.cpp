//
// Created by drpsy on 17-Nov-18.
//

#include "qstring_token_generator.hpp"

qstring_token_generator::qstring_token_generator(char open_q, char close_q, char esc_c, bool skip_empty) :
    start_marker(open_q),
    end_marker(close_q),
    escape_char(esc_c),
    skip_empty_tokens(skip_empty),
    in_token(false),
    in_escape(false) {}

void qstring_token_generator::reset() {
  in_token = false;
  in_escape = false;
}

qstring_token_generator::iterator qstring_token_generator::start_token(qstring_token_generator::iterator &next) {
  in_token = true;
  return ++next;
}

std::string qstring_token_generator::end_token(qstring_token_generator::iterator &next,
                                               qstring_token_generator::iterator token_start) {
  in_token = false;
  auto token_end = next++;
  return std::string(token_start, token_end);
}

bool qstring_token_generator::operator()(qstring_token_generator::iterator &next,
                                              qstring_token_generator::iterator end,
                                              std::string &token) {
  iterator token_start;

  // Loop through the successive characters of the input
  while (next != end) {
    if (in_escape) {
      // unset in_escape after reading the next char
      in_escape = false;
    } else if (*next == start_marker) { // found start marker
      if (!in_token) {  // potential new token
        token_start = start_token(next);
        continue;
      } else {  // already in a quoted string
        if (start_marker == end_marker) {
          // found end marker, is equal to start_marker
          token = end_token(next, token_start);
          if (!token.empty() || !skip_empty_tokens) {
            return true;
          }
        } else {
          // Multiple start markers without end marker. Discard previous start markers, consider
          // inner-most token only.
          token_start = start_token(next);
          continue;
        }
      }
    } else if (*next == end_marker) {
      // found end marker, is not equal to start marker
      if (in_token) {
        token = end_token(next, token_start);
        if (!token.empty() || !skip_empty_tokens) {
          return true;
        }
      }
    } else if (*next == escape_char) {
      in_escape = !in_escape; // toggle
    }
    ++next;
  }
  return false;
}