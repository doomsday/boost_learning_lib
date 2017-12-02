//
// Created by drpsy on 02-Dec-17.
//

#ifndef BOOST_ASIO_NPCBOOK_PRINT_VISITOR_HPP
#define BOOST_ASIO_NPCBOOK_PRINT_VISITOR_HPP

#include <boost/variant.hpp>
#include <iostream>

/*
 *  As long as all the types in the variant are streamable, this code will
 *  compile and print the value of the variant to the standard output.
 */
struct print_visitor : boost::static_visitor<> {
  template<typename T>
  void operator()(const T &t) const {
    std::cout << t << '\n';
  }
};

#endif //BOOST_ASIO_NPCBOOK_PRINT_VISITOR_HPP
