#pragma once
#include "helpers.hpp"
namespace monads_demo {
using namespace helpers;

namespace views = std::ranges::views;

auto concate_prefix = [](std::string name) {
  return std::make_optional("User: " + name);
};

auto capitalize = [](std::string str) {
  std::transform(str.begin(), str.end(), str.begin(), ::toupper);
  return std::make_optional(str);
};

void functor() {
  struct MyFunctor {
  public:
    int operator()(int x) { return x * 2; }
  };

  MyFunctor doubler;
  int x = doubler(doubler(5));
  std::cout << "doubler: " << x;
}

std::optional<std::string> transform_user(std::optional<std::string> name) {
  if (!name) {
    return {};
  }
  std::optional<std::string> user_str = concate_prefix(name.value());
  if (!user_str) {
    return {};
  }
  return capitalize(user_str.value());
}

std::optional<std::string>
monadic_transform_user(std::optional<std::string> name = std::nullopt) {
  return mbind(mbind(name, concate_prefix), capitalize);
}

void optional_monad() {
  transform_user("Amar Lakshya");
  mbind(monadic_transform_user("amar lakshya"), mprint);
}

void start() {
  std::cout << "\nMonads Demo:\n";
  functor();
  std::cout << "\n";
  optional_monad();
}

} // namespace monads_demo
