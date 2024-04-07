#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

auto main() -> int {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, x;
    std::cin >> n >> x;
    std::vector<int> v1, v2;
    for (int i = 0; i < n / 2; i++) {
        int aux;
        std::cin >> aux;
        v1.push_back(aux);
    }
    for (int i = n / 2; i < n; i++) {
        int aux;
        std::cin >> aux;
        v2.push_back(aux);
    }

    int tam1 = n / 2, tam2 = (n + 1) / 2, tam;
    std::vector<int64_t> resp1(1), resp2(1);
    for (int i = 0; i < tam1; i++) {
        tam = static_cast<int>(resp1.size());
        for (int j = 0; j < tam; j++) resp1.push_back(resp1[j] + v1[i]);
    }
    for (int i = 0; i < tam2; i++) {
        tam = static_cast<int>(resp2.size());
        for (int j = 0; j < tam; j++) resp2.push_back(resp2[j] + v2[i]);
    }
    std::ranges::sort(resp1);
    std::ranges::sort(resp2);
    int64_t ans = 0;
    for (auto a: resp1) {
        if (a > x) break;
        int64_t look = x - a;
        auto l = std::ranges::lower_bound(resp2, look);
        auto r = std::ranges::upper_bound(resp2, look);
        ans += std::ranges::distance(l, r);
    }
    std::cout << ans;
}