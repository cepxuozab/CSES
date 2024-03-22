#include <algorithm>
#include <iostream>
#include <vector>

[[maybe_unused]] static auto const FastIo = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

auto main() -> int {
    int n;
    std::cin >> n;
    std::vector<int> vec(n);
    for (int& v : vec) {
        std::cin >> v;
    }
    auto MX = std::ranges::max(vec);
    std::vector<int> freq(MX + 1);
    for (int v : vec) {
        freq[v]++;
    }
    for (int i = MX; i >= 1; i--) {
        for (int cnt = 0, j = i; j <= MX; j += i) {
            if (freq[j] >= 2) {
                std::cout << j;
                exit(0);
            }
            if ((cnt += static_cast<int>(freq[j] == 1)) == 2) {
                std::cout << i;
                exit(0);
            }
        }
    }
}