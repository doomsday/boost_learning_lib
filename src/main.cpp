#include <iostream>
#include <boost/variant.hpp>

#include "variant_json.hpp"

int main() {

  json_value person1 = json_object();
  json_value person2 = json_object();
  json_value person3 = json_object();

  json_object
      *pp1 = boost::get<json_object>(&person1),
      *pp2 = boost::get<json_object>(&person2),
      *pp3 = boost::get<json_object>(&person3);

  (*pp1)["name"] = std::string("Mike Morbid");
  (*pp1)["profession"] = std::string("farmer");
  (*pp1)["age"] = 21L;
  (*pp1)["favourite"] = std::string("Cannibal Corpse");
  (*pp1)["height"] = 176.1;

  (*pp2)["name"] = std::string("Stuart Regret");
  (*pp2)["profession"] = std::string("programmer");
  (*pp2)["age"] = 4L;
  (*pp2)["favourite"] = std::string("Suffocation");
  (*pp2)["height"] = 11.0;

  (*pp3)["name"] = std::string("Howard Roark");
  (*pp3)["profession"] = std::string("architect");
  (*pp3)["age"] = 32L;
  (*pp3)["favourite"] = std::string("Eggs benedict");
  (*pp3)["height"] = 185.0;

  json_value vt = json_array();
  json_array *array = boost::get<json_array>(&vt);
  array->push_back(person1);
  array->push_back(person2);
  array->push_back(person3);

  boost::apply_visitor(json_print_visitor(), vt);

  return EXIT_SUCCESS;
}

