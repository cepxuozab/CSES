#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

[[maybe_unused]] static const auto FastIo = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

struct Project {
    int starting = 0;
    int ending = 0;
    int reward = 0;

    auto operator<=>(Project const &) const = default;
};

auto main() -> int {
    int n;
    std::cin >> n;
    std::vector<Project> projects(n);
    for (auto &[s, e, r]: projects) {
        std::cin >> e >> s >> r;
    }
    std::ranges::sort(projects);
    std::vector<int64_t> amount(n);
    amount[0] = projects.front().reward;
    for (int i = 1; i < n; ++i) {
        auto const [y, x, z] = projects[i];
        auto k = std::lower_bound(projects.begin(), projects.end(), Project(x, 0, 0)) - projects.begin() - 1;
        auto m = amount[i - 1];
        if (k >= 0) {
            m = std::max(m, amount[k] + z);
        } else {
            m = std::max<int64_t>(m, z);
        }
        amount[i] = m;
    }
    std::cout << amount.back() << '\n';
}