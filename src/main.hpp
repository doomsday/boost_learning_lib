//
// Created by drpsy on 19-Nov-17.
//

#ifndef BOOST_ASIO_NPCBOOK_MAIN_HPP
#define BOOST_ASIO_NPCBOOK_MAIN_HPP

#include <limits>
#include <cstddef>
#include <tuple>
#include <vector>

std::tuple<size_t, size_t, double> get_best_transact_days(const std::vector<double> &prices) {
  double min = std::numeric_limits<double>::max();
  double gain = 0.0, max_gain = 0.0;
  size_t min_day, max_day;
  size_t buy_day;

  for(size_t i=0, days = prices.size(); i < days; ++i) {
    if (prices[i] < min) {
      min = prices[i];
      min_day = i;
    } else if ((gain = prices[i] - min) > max_gain) {
      max_gain = gain;
      buy_day = min_day;
      max_day = i;
    }
  }

  return {buy_day, max_day, max_gain};
}

template <typename T>
size_t tuple_length(const T&) {
  return std::tuple_size<T>::value;
}

std::vector<double> get_test_data() {
  std::vector<double> prices;
  prices.push_back(0.1);
  prices.push_back(3.6);
  prices.push_back(8.99);
  prices.push_back(155.554);
  prices.push_back(12.22);
  prices.push_back(67.45);
  prices.push_back(9.166);
  prices.push_back(76.789);
  prices.push_back(22.56);
  prices.push_back(17.90);
  prices.push_back(6.19);
  prices.push_back(55.39);
  prices.push_back(89.288);

  return prices;
}

#endif //BOOST_ASIO_NPCBOOK_MAIN_HPP
