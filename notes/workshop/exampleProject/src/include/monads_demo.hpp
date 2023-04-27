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
  transform_user("amar lakshya");
  mbind(monadic_transform_user("amar lakshya"), mprint);
}

void start() {
  std::cout << "\nMonads Demo:\n";
  optional_monad();
}

} // namespace monads_demo
