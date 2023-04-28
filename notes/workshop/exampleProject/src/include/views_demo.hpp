#pragma once
#include "helpers.hpp"

namespace views_demo {
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

  print_view(views::iota(1, 5) | views::filter(even) |
                 views::transform(multiplyBy2),
             "views answer: ");
}

void view_operation() {
  std::vector<int> numbers = {42, 9, 0, 16, 7, -1, 13};
  print(numbers, "original: ");
  print_view(numbers | views::take(3) | views::transform(std::negate{}),
             "transformed: ");
}

void view_read_only() {
  std::vector vec{1, 2, 3, 4, 5, 6};
  print(vec, "original vector:");
  auto v = vec | views::reverse | views::drop(2);
  print(v, "view before update:");
  *v.begin() = 42;
  print(v, "view after update:");
}

std::vector<int> collection() { return {1,2,3,4,5,6}; };

void view_const() {
  std::vector<int> vec = collection();
  print(vec, "original vector:");
  const auto v = vec |  views::drop(2); // drop_view<ref_view<vector<int>>
  print(v, "const view before update:");
  *v.begin() = 42;
  print(v, "const view after update:");
}

void start() {
  std::cout << "\nViews Demo:\n";
  motivation();
  std::cout << "\n";
  view_operation();
  std::cout << "\n";
  view_read_only();
  std::cout << "\n";
  view_const();

}

} // namespace views_demo
