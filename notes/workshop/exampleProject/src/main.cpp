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

void print(auto begin, auto end) {
  for (auto pos = begin; pos != end; ++pos) {
    std::cout << *pos << ' ';
  }
  std::cout << '\n';
}

template <auto Val> struct EndValue {
  bool operator==(auto pos) const { return *pos = Val; }
};

void sentinel_support() {
  std::vector v{1, 2, 3, 4, -1, 5, 6};
  print(v.begin(), v.end());
  print(v.begin(), EndValue<-1>{});
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
  std::cout << result << "\n";
}

int main() {
  sentinel_support();
  concept_errors();
  range_overloads();
}
