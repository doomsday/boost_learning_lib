#include <string>
#include <iostream>
#include <boost/container/flat_map.hpp>

int main() {

  using Capitals = boost::container::flat_map<std::string, std::string>;
  Capitals newCapitals;

  newCapitals["Sri Lanka"] = "Sri Jayawardenepura Kotte";
  newCapitals["Burma"] = "Naypyidaw";
  newCapitals["Tanzania"] = "Dodoma";
  newCapitals["Cote d'Ivoire"] = "Yamoussoukro";
  newCapitals["Nigeria"] = "Abuja";
  newCapitals["Kazakhstan"] = "Astana";
  newCapitals["Palau"] = "Ngerulmud";
  newCapitals["Federated States of Micronesia"] = "Palikir";

  for (const auto& entries : newCapitals) {
    std::cout << entries.first << ": " << entries.second << '\n';
  }

  return EXIT_SUCCESS;
}