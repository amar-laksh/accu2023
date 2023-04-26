#pragma once
#include <iostream>
#include <vector>

namespace helpers {
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

void print(auto begin, auto end, std::string const &msg = "") {
  if (!msg.empty())
    std::cout << msg << "\n";
  for (auto pos = begin; pos != end; ++pos) {
    std::cout << *pos << ' ';
  }
  std::cout << '\n';
}
}; // namespace helpers
