#pragma once
#include "helpers.hpp"
#include <list>

namespace ranges_demo {
using namespace helpers;

void concept_errors() {
  std::list<int> list{1, 2, 3, 4};
  // std::sort(list.begin(), list.end());
  // std::ranges::sort(list.begin(), list.end());
}

void range_overloads() {
  auto getData = [] { return std::vector{1, 2, 3, 4, 5, 6, 7, 8}; };
  auto result = std::all_of(getData().begin(), getData().end(),
                            [](const int i) { return i < 3; });

  // auto result =
  //     std::ranges::all_of(getData(), [](const int i) { return i < 3; });
  std::cout << "all_of result is: " << result << "\n";
}

void projections_support() {
  std::vector<UnitedKingdom> uk{{.country = "England", .rank = 3},
                                {.country = "Scotland", .rank = 1},
                                {.country = "Wales", .rank = 2}};

  print_country(uk, "unsorted countries:");
  std::sort(uk.begin(), uk.end(),
            [](UnitedKingdom const &x, UnitedKingdom const &y) {
              return x.rank < y.rank;
            });
  // std::ranges::sort(uk, {}, &UnitedKingdom::rank);

  print_country(uk, "sorted countries:");
}

template <auto Val> struct EndValue {
  bool operator==(auto pos) const { return *pos == Val; }
};

void sentinel_support() {
  std::vector v{3, 2, 1, 4, -1, 6, 5};
  print(v.begin(), v.end(), "unsorted:");
  std::ranges::sort(v);
  print(v.begin(), v.end(), "sorted:");
  v = {3, 2, 1, 4, -1, 6, 5};
  std::ranges::sort(v.begin(), EndValue<5>{});
  print(v.begin(), v.end(), "sort with sentinel at 5:");
  print(v.begin(), EndValue<5>{}, "printing with sentinel at 5:");
  // print(v.begin(), EndValue<100>{}, "printing with sentinel at 100:");
  // print(v.begin(), std::unreachable_sentinel);
}

void start() {
  std::cout << "\nRanges Demo:\n";
  concept_errors();
  std::cout << "\n";
  range_overloads();
  std::cout << "\n";
  projections_support();
  std::cout << "\n";
  sentinel_support();
  std::cout << "\n";
}
} // namespace ranges_demo
