#include <iostream>
#include <vector>
#include <numeric>


auto AppleDivision(std::vector<int> const &apples) -> long long {
    long long sum = std::accumulate(apples.begin(), apples.end(), 0LL);
    int const n = static_cast<int>(apples.size());
    long long ans = 0;
    for (int i = 0; i < 1 << n; i++) {
        long long cs = 0;
        for (int j = 0; j < n; j++) {
            if (i >> j & 1) cs += apples[j];
        }
        if (cs <= sum / 2) ans = std::max(ans, cs);
    }
    return sum - 2LL * ans;
}

auto main() -> int {
    int n;
    std::cin >> n;
    std::vector<int> apple_weights(n);
    for (int &weight: apple_weights) {
        std::cin >> weight;
    }
    std::cout << AppleDivision(apple_weights) << '\n';
    return 0;
}