#include <algorithm>
#include <functional>
#include <iostream>
#include <memory>
#include <vector>

[[maybe_unused]] static const auto FastIO = []() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return nullptr;
}();

using T = int64_t;

struct Tree {
  static constexpr T unit = 0;
  static auto func(T a, T b) -> T { return a + b; } // (any associative fn)
  std::vector<T> s;
  int n;
  Tree(int n = 0, T def = unit) : s(2 * n, def), n(n) {}
  void update(int pos, T val) {
    for (s[pos += n] = val; pos /= 2;) {
      s[pos] = func(s[pos * 2], s[pos * 2 + 1]);
    }
  }
  auto query(int b, int e) -> T { // query [b, e)
    T ra = unit;
    T rb = unit;
    for (b += n, e += n; b < e; b /= 2, e /= 2) {
      if ((b % 2) != 0) {
        ra = func(ra, s[b++]);
      }
      if ((e % 2) != 0) {
        rb = func(s[--e], rb);
      }
    }
    return func(ra, rb);
  }
};

using Graph = std::vector<std::vector<int>>;

int main() {
  int n;
  int q;
  std::cin >> n >> q;
  std::vector<int> values(n);
  for (int &val : values) {
    std::cin >> val;
  }
  Graph graph(n);
  for (int i = 0; i < n - 1; ++i) {
    int a;
    int b;
    std::cin >> a >> b;
    a--;
    b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  std::vector<int> left(n);
  std::vector<int> right(n);
  int time = 0;
  std::function<void(int, int)> dfs = [&](int i, int p) {
    left[i] = time++;
    for (int j : graph[i]) {
      if (j != p) {
        dfs(j, i);
      }
    }
    right[i] = time;
  };
  dfs(0, -1);
  auto tree = std::make_unique<Tree>(n);
  for (int i = 0; i < n; ++i) {
    tree->update(left[i], values[i]);
  }
  while ((q--) != 0) {
    int type;
    int a;
    int b;
    std::cin >> type >> a;
    a--;
    if (type == 1) {
      std::cin >> b;
      tree->update(left[a], b);
    } else {
      std::cout << tree->query(left[a], right[a]) << std::endl;
    }
  }
}
