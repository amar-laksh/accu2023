#pragma once
#include "helpers.hpp"

using namespace helpers;

namespace views = std::ranges::views;
void motivation() {

  auto even = [](int n) { return n % 2 == 0; };
  auto multiplyBy2 = [](int n) { return n * 2; };

  std::vector<int> numbers = {1, 2, 3, 4, 5};
  std::vector<int> evenNumbers;
  std::copy_if(begin(numbers), end(numbers), std::back_inserter(evenNumbers),
               even);
  std::vector<int> results;
  std::transform(begin(evenNumbers), end(evenNumbers),
                 std::back_inserter(results), multiplyBy2);
  print(results.begin(), results.end(), "iterator answer: ");

  auto result =
      views::iota(1, 5) | views::filter(even) | views::transform(multiplyBy2);
  print(result, "ranges/views answer: ");
}

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
  // std::cout << "all_of result is: " << result << "\n";
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
  // Whenever you have a range where the end is some dynamic condition instead
  // of a fixed position, use an iterator and sentinel pair instead.
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

void ranges_demo() {
  motivation();
  std::cout << "\n";
  concept_errors();
  std::cout << "\n";
  range_overloads();
  std::cout << "\n";
  projections_support();
  std::cout << "\n";
  sentinel_support();
  std::cout << "\n";
}