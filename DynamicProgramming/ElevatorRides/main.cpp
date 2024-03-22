#include <iostream>
#include <vector>

[[maybe_unused]] static const auto FastIo = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

auto main() -> int {
    int n, x;
    std::cin >> n >> x;
    std::vector<int> w(n);
    for (int i = 0; i < n; i++)std::cin >> w[i];
    std::vector<std::pair<int, int>> best(1 << n);
    best[0] = {1, 0};

    for (int mask = 1; mask < (1 << n); mask++) {
        best[mask] = {n + 1, 0};
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                auto option = best[mask ^ (1 << i)];
                if (option.second + w[i] <= x) {
                    option = {option.first, option.second + w[i]};
                } else option = {option.first + 1, w[i]};
                best[mask] = min(best[mask], option);
            }
        }
        best[mask] = best[mask];
    }
    std::cout << best[(1 << n) - 1].first << "\n";

}