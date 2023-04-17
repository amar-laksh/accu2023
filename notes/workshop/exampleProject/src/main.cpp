#include <map>
#include <set>
#include <vector>

template <typename PairT>
concept EmptyConst = requires(PairT p) {
  []() {}();
};

int main(int argc, char *argv[]) {
  std::vector<int> coll1;
  std::set<int> coll2;
  std::map<int, int> myMap;
  for (EmptyConst auto [key, value] : myMap) {
  }

  return 0;
}
