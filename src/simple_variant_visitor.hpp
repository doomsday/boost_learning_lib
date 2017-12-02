//
// Created by drpsy on 02-Dec-17.
//

#ifndef BOOST_ASIO_NPCBOOK_SIMPLE_VARIANT_VISITOR_HPP
#define BOOST_ASIO_NPCBOOK_SIMPLE_VARIANT_VISITOR_HPP

#include <boost/variant.hpp>
#include <iostream>

struct simple_variant_visitor: public boost::static_visitor<void>
{
  void operator() (const std::string& s) const {
    std::cout << "String: " << s << '\n';
  }

  void operator() (long n) const {
    std::cout << "long: " << n << '\n';
  }
};

#endif //BOOST_ASIO_NPCBOOK_SIMPLE_VARIANT_VISITOR_HPP
