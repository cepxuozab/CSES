#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

constexpr int MOD = 1e9 + 7;

struct BIT {
    int n_;
    std::vector<int> fen_tree_;

    explicit BIT(int n) : n_(n), fen_tree_(n) {
    }

    auto Sum(int idx) -> int {
        int ans = 0;
        for (int i = idx; i > 0; i -= i & -i) {
            (ans += fen_tree_[i]) %= MOD;
        }
        return ans;
    }

    void Update(int idx, int val) {
        for (int i = idx; i < n_; i += i & -i) {
            (fen_tree_[i] += val) %= MOD;
        }
    }
};

auto main() -> int {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int &a: arr) {
        std::cin >> a;
    }
    auto tmp = arr;
    std::ranges::sort(tmp);
    int idx = 1;
    std::map<int, int> mapper;
    for (int elem: tmp) {
        mapper[elem] = idx;
        idx++;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = mapper[arr[i]];
    }
    BIT tree(n + 1);
    int ans = 0;
    for (auto x: arr) {
        int val = 1 + tree.Sum(x - 1);
        (ans += val) %= MOD;
        tree.Update(x, val);
    }
    std::cout << ans << '\n';
}
