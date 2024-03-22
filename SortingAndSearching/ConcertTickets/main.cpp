
#include <iostream>
#include <set>

[[maybe_unused]] static const auto _ = []() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return nullptr;
}();

auto main() -> int {
  int n;
  int m;
  std::cin >> n >> m;
  unsigned x;
  std::multiset<unsigned, std::greater<>> sets;
  while (n-- != 0) {
    std::cin >> x;
    sets.insert(x);
  }
  while (m-- != 0) {
    std::cin >> x;
    if (auto it = sets.lower_bound(x); it != sets.end()) {
      std::cout << *it << '\n';
      sets.erase(it);
    } else {
      std::cout << "-1\n";
    }
  }
  return 0;
}
