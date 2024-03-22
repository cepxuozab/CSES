#include <algorithm>
#include <cstdint>
#include <iostream>
#include <utility>
#include <vector>

[[maybe_unused]] static auto const FastIo = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();
auto LinearSieve(int n) -> std::vector<int64_t> {
    std::vector<int64_t> spf(n + 1);
    std::vector<int64_t> primes;
    for (int i = 2; i <= n; i++) {
        if (spf[i] == 0) {
            spf[i] = i;
            primes.push_back(i);
        }
        for (int j = 0;
             std::cmp_less(j, primes.size()) && primes[j] <= spf[i] && i * primes[j] <= n; j++) {
            spf[i * primes[j]] = primes[j];
        }
    }
    return spf;
}

auto mobius(int n) -> std::vector<int64_t> {
    std::vector<int64_t> mu(n + 1, 1);
    auto const spf = LinearSieve(n);
    for (int i = 2; i <= n; i++) {
        if (spf[i] == spf[i / spf[i]])
            mu[i] = 0;
        else
            mu[i] = -mu[i / spf[i]];
    }
    return mu;
}

auto main() -> int {
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (int& x : v) std::cin >> x;

    int maxV = std::ranges::max(v);
    auto const mu = mobius(maxV);
    std::vector<int64_t> count(maxV + 1, 0);

    for (int x : v) count[x]++;
    for (int i = 1; i <= maxV; i++) {
        for (int j = 2 * i; j <= maxV; j += i) {
            count[i] += count[j];
        }
    }
    int64_t ans = 0;
    for (int i = 1; i <= maxV; i++) {
        if (mu[i] == 0) continue;
        ans += mu[i] * (count[i] * (count[i] - 1) / 2);
    }

    std::cout << ans << '\n';
}