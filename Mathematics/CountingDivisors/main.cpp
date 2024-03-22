#include <iostream>
#include <numeric>
#include <vector>

auto Sieve_of_Eratosthenes(int n) -> std::vector<int> {
    std::vector<int> sieve(n + 1);
    std::iota(sieve.begin(), sieve.end(), 0);
    for (int p = 2; p * p <= n; p++) {
        if (sieve[p] == p) {
            for (int i = p * p; i <= n; i += p)
                if (sieve[i] == i)
                    sieve[i] = p;
        }
    }
    return sieve;
}

int main() {
    int n;
    std::cin >> n;
    auto sieve = Sieve_of_Eratosthenes(1000000);
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        int ans = 1;
        while (x != 1) {
            int y = sieve[x];
            int c = 1;
            while (x % y == 0) {
                c++;
                x /= y;
            }
            ans *= c;
        }
        printf("%d\n", ans);
    }
}
