#pragma once
#include "helpers.hpp"
namespace monads_demo {
using namespace helpers;

namespace views = std::ranges::views;

std::variant<std::string, int>
transform_user(std::variant<std::string, int> name) {
  if (name.index() == 1) {
    return -1;
  }
  std::variant<std::string, int> user_str =
      concat_prefix(std::get<std::string>(name));
  if (user_str.index() == 1) {
    return -2;
  }
  return capitalize(std::get<std::string>(user_str));
}

std::variant<std::string, int>
monadic_transform_user(std::variant<std::string, int> name) {
  return vbind(vbind(name, concat_prefix), capitalize);
  // return foldl(vbind, name, {concat_prefix, capitalize, decapitalize});
}

void variant_monad() {
  print_variant(monadic_transform_user("amar lakshya"));
  print_variant(monadic_transform_user("mamar lakshya"));
  print_variant(monadic_transform_user("amar"));
}

void start() {
  std::cout << "\nMonads Demo:\n";
  variant_monad();
}

} // namespace monads_demo
