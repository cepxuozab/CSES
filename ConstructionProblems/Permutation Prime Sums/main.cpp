#include <iostream>
#include <vector>


int main() {
    std::cin.tie(0)->sync_with_stdio(0);
    int max_n = 1e6;
    std::vector<int> is_prime(max_n + 1, 1);
    auto sieve = [&]() {
        is_prime[0] = is_prime[1] = 0;
        for (int i = 2; i * i <= max_n; i++) {
            if (is_prime[i]) {
                for (int j = i * i; j <= max_n; j += i) {
                    is_prime[j] = 0;
                }
            }
        }
    };
    std::vector<int> primes;
    sieve();
    for (int i = 2; i <= max_n; i++) {
        if (is_prime[i]) primes.push_back(i);
    }
    int n;
    std::cin >> n;
    std::vector<int> ans(n);
    if (n == 1) {
        std::cout << "1\n1\n";
        return 0;
    }
    int cur = n;
    while (cur > 0) {
        int p = *upper_bound(primes.begin(), primes.end(), cur);
        for (int i = cur; i >= p - cur; i--) {
            ans[i - 1] = p - i;
        }
        cur = p - cur - 1;
    }

    for (int i = 0; i < n; i++) {
        std::cout << i + 1 << " \n"[i == n - 1];
    }
    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << " \n"[i == n - 1];
    }
    return 0;

}
