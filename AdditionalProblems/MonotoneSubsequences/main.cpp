#include <iostream>
#include <optional>
#include <vector>

auto MonotoneSubsequences(int n, int k) -> std::optional<std::vector<int>> {
    if (k * k < n) {
        return std::nullopt;
    }
    std::vector<int> ans;
    int l = 1, r = k;
    while (true) {
        for (int i = r; i >= l; i--) ans.push_back(i);
        if (r == n) break;
        l = r + 1;
        r = std::min(r + k, n);
    }
    return ans;
}

void Print(std::optional<std::vector<int>> ans) {
    if (!ans.has_value()) {
        std::cout << "IMPOSSIBLE" << '\n';
    } else {
        for (int i : ans.value()) {
            std::cout << i << ' ';
        }
        std::cout << '\n';
    }
}

auto main() -> int {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        int n, k;
        std::cin >> n >> k;
        Print(MonotoneSubsequences(n, k));
    }
}
