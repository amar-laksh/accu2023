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

std::variant<std::string, int> decapitalize(std::string str) {
  if (str.ends_with("A")) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
  } else {
    return -2;
  }
}

void print_variant(std::variant<std::string, int> str) {
  if (str.index() == 1) {
    std::cout << "I got an error value: " << std::get<int>(str) << '\n';
  } else {
    for (auto v : std::get<std::string>(str)) {
      std::cout << v;
    }
    std::cout << '\n';
  }
}

std::variant<std::string, int>
vbind(const std::variant<std::string, int> &opt,
      std::function<std::variant<std::string, int>(std::string)> f) {
  if (opt.index() == 1) {
    return std::get<int>(opt);
  } else {
    return f(std::get<std::string>(opt));
  }
}

template <class MapFn, class ValueType, class Fn>
ValueType foldl(MapFn m, ValueType &opt, std::initializer_list<Fn> fns) {
  for (auto &fn : fns) {
    auto r = m(opt, fn);
    opt = r;
  }
  return opt;
}
}; // namespace helpers
