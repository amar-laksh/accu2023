#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <vector>

template <typename PairT>
concept EmptyConst = requires(PairT p) {
  []() {}();
};

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

void projections_support() {}

void print(auto begin, auto end, std::string const &msg = "") {
  if (!msg.empty())
    std::cout << msg << "\n";
  for (auto pos = begin; pos != end; ++pos) {
    std::cout << *pos << ' ';
  }
  std::cout << '\n';
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
  // print(v.begin(), std::unreachable_sentinel);
}

int main() {
  concept_errors();
  range_overloads();
  projections_support();
  sentinel_support();
}
