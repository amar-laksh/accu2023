#include <iostream>
#include <map>
#include <ranges>
#include <set>
#include <vector>

template <typename PairT>
concept EmptyConst = requires(PairT p) {
  []() {}();
};

int main(int argc, char *argv[]) {
  std::vector v{1, 2, 3, 4, 5, 6};
  return 0;
}
