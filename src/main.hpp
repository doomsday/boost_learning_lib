//
// Created by drpsy on 19-Nov-17.
//

#ifndef BOOST_ASIO_NPCBOOK_MAIN_HPP
#define BOOST_ASIO_NPCBOOK_MAIN_HPP

class Foo {
  int id_;
 public:
  explicit Foo(int n = 0) : id_(n) {} // int convertible to Foo.
};

class Bar {
  int id_;
 public:
  explicit Bar(int n = 0) : id_(n) {} // int convertible to Bar.
};

#endif //BOOST_ASIO_NPCBOOK_MAIN_HPP
