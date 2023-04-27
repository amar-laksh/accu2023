#pragma once
#include <algorithm>
#include <iostream>
#include <list>
#include <ranges>
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

std::optional<std::string> mprint(std::string range) {
  for (auto v : range) {
    std::cout << v;
  }
  std::cout << '\n';
  return {};
}

template <typename T, typename F>
auto mbind(const std::optional<T> &opt, F f) -> decltype(f(opt.value())) {
  if (opt) {
    return f(opt.value());
  } else {
    return {};
  }
}

}; // namespace helpers
