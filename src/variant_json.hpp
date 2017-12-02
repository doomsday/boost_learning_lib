//
// Created by drpsy on 02-Dec-17.
//

#ifndef BOOST_ASIO_NPCBOOK_VARIANT_JSON_HPP
#define BOOST_ASIO_NPCBOOK_VARIANT_JSON_HPP

#define BOOST_VARIANT_NO_FULL_RECURSIVE_VARIANT_SUPPORT

#include <sstream>
#include <string>
#include <boost/variant.hpp>
#include <map>
#include <vector>

struct json_null_type {};

typedef boost::make_recursive_variant<std::string,
                                      double,
                                      long,
                                      bool,
                                      json_null_type,
                                      std::map<std::string, boost::recursive_variant_>, // JSON object.
                                      std::vector<boost::recursive_variant_>            // JSON array.
>::type json_value;

typedef std::map<std::string, json_value> json_object;    // JSON object.
typedef std::vector<json_value> json_array;               // JSON array.

void print_array_element(const json_value &);
void print_object_attribute(const json_object::value_type &);
std::string escape_str(const std::string &input);

struct json_print_visitor : public boost::static_visitor<void> {

  // JSON Strings.
  void operator()(const std::string &str) const {
    std::cout << '"' << escape_str(str) << '"';
  }

  // JSON empty objects.
  void operator()(const json_null_type &) const {
    std::cout << "null";
  }

  // JSON streamable types.
  template<typename T>
  void operator()(const T &value) const {
    std::cout
        << std::boolalpha // Sets the 'boolalpha' format flag: values are inserted/extracted by their
        // textual representation: either true or false, instead of integral values.
        << value;
  }

  // JSON arrays.
  void operator()(const json_array &arr) const {
    std::cout << '[';
    if (!arr.empty()) {
      boost::apply_visitor(*this, arr[0]);  // Print first array item.
      std::for_each(arr.begin() + 1, arr.end(), print_array_element);  // Print subsequent elements separated by ","
    }
    std::cout << ']';
  }

  // JSON objects.
  void operator()(const json_object &object) const {
    std::cout << '{';
    if (!object.empty()) {
      const auto &kv_pair = *(object.begin());
      std::cout << '"' << escape_str(kv_pair.first) << '"';
      std::cout << ':';
      boost::apply_visitor(*this, kv_pair.second);

      auto it = object.begin();
      std::for_each(++it, object.end(), print_object_attribute);
    }
    std::cout << '}';
  }
};

void print_array_element(const json_value &value) {
  std::cout << ',';
  boost::apply_visitor(json_print_visitor(), value);
}

void print_object_attribute(const json_object::value_type &val) {
  std::cout << ',';
  std::cout << '"' << escape_str(val.first) << '"';
  std::cout << ':';
  boost::apply_visitor(json_print_visitor(), val.second);
}

std::string escape_str(const std::string &input) {
  std::ostringstream ss;
  for (char iter : input) {
    switch (iter) {
      case '\\': ss << "\\\\";
        break;
      case '"': ss << "\\\"";
        break;
      case '/': ss << "\\/";
        break;
      case '\b': ss << "\\b";
        break;
      case '\f': ss << "\\f";
        break;
      case '\n': ss << "\\n";
        break;
      case '\r': ss << "\\r";
        break;
      case '\t': ss << "\\t";
        break;
      default: ss << iter;
        break;
    }
  }
  return ss.str();
}

#endif //BOOST_ASIO_NPCBOOK_VARIANT_JSON_HPP
