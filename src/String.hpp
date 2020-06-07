//
// Created by drpsy on 6/8/2020.
//

#ifndef BOOST_ASIO_NPCBOOK_STRING_HPP
#define BOOST_ASIO_NPCBOOK_STRING_HPP

#include <boost/move/move.hpp>
#include <boost/swap.hpp>
#include <cstring>

class String {

 private:
  BOOST_MOVABLE_BUT_NOT_COPYABLE(String)

 public:

  explicit String(const char *s = nullptr) : str(nullptr), sz(0) {
    str = heapcpy(s, sz);
  }

  ~String() {
    delete[] str;
    sz = 0;
  }

  String(BOOST_RV_REF(String) that)  noexcept : str(nullptr), sz(0) {
    swap(that);
  }

  String& operator = (BOOST_RV_REF(String) rhs)  noexcept {
    String tmp(boost::move(rhs));
    return *this;
  }

  void swap(String& rhs) {
    boost::swap(this->sz, rhs.sz);
    boost::swap(this->str, rhs.str);
  }

  [[nodiscard]] const char *get() const {
    return str;
  }

 private:
  char *str;
  size_t sz;

  static char *heapcpy(const char *str, size_t& sz) {
    char *ret = nullptr;
    if (str) {
      sz = std::strlen(str) + 1;
      ret = new char[sz];
      std::strncpy(ret, str, sz);
    }
    return ret;
  }

};

#endif //BOOST_ASIO_NPCBOOK_STRING_HPP
