#pragma once
#include <algorithm>
#include <iostream>
#include <list>
#include <ranges>
#include <variant>
#include <vector>

namespace helpers {
namespace views = std::views;
struct UnitedKingdom {
  std::string country;
  int rank;
};

void print_country(std::vector<UnitedKingdom> const &uk,
                   std::string const &msg = "") {
  if (!msg.empty())
    std::cout << msg << "\n";

  for (auto c : uk) {
    std::cout << c.country << ", rank = " << c.rank << '\n';
  }
}

void print(auto begin, auto end, std::string const &msg) {
  if (!msg.empty())
    std::cout << msg << "\n";
  for (auto pos = begin; pos != end; ++pos) {
    std::cout << *pos << ' ';
  }
  std::cout << '\n';
}

void print(std::ranges::input_range auto &range, std::string const &msg) {
  if (!msg.empty())
    std::cout << msg << "\n";
  for (auto v : range) {
    std::cout << v << ' ';
  }
  std::cout << '\n';
}

void print_view(std::ranges::view auto &&range, std::string const &msg) {
  if (!msg.empty())
    std::cout << msg << "\n";
  for (auto v : range) {
    std::cout << v << ' ';
  }
  std::cout << '\n';
}

template <typename T> using optional = std::variant<T, int>;

std::variant<std::string, int> concat_prefix(std::string name) {
  if (name.starts_with("a")) {
    return "User: " + name;
  } else {
    return -1;
  }
}

std::variant<std::string, int> capitalize(std::string str) {
  if (str.ends_with("a")) {
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
  } else {
    return -2;
  }
}

template <typename Valid, typename Invalid>
void print_variant(std::variant<Valid, Invalid> str) {
  if (str.index() == 1) {
    std::cout << "I got an error value: " << std::get<Invalid>(str) << '\n';
  } else {
    for (auto v : std::get<Valid>(str)) {
      std::cout << v;
    }
    std::cout << '\n';
  }
}

template <typename Valid, typename Invalid, typename F>
std::variant<Valid, Invalid> vbind(const std::variant<Valid, Invalid> &opt,
                                   F f) {
  if (opt.index() == 1) {
    return std::get<Invalid>(opt);
  } else {
    return f(std::get<Valid>(opt));
  }
}

}; // namespace helpers
