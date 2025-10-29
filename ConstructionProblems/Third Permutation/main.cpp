#include <iostream>
#include <vector>
#include <random>
#include <chrono>

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
    std::cin.tie(0)->sync_with_stdio(0);
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int &i: a)
        std::cin >> i;
    for (int &i: b)
        std::cin >> i;
    std::vector<int> c(n);
    iota(begin(c), end(c), 1);
    for (int i = 0; i < 100; i++) {
        shuffle(begin(c), end(c), rng);
        bool ok = true;
        for (int j = 0; j < n; j++)
            ok &= (a[j] != c[j] && b[j] != c[j]);
        if (ok) {
            for (int j = 0; j < n; j++)
                std::cout << c[j] << " \n"[j == n - 1];
            return 0;
        }
    }
    std::cout << "IMPOSSIBLE\n";
    return 0;
}
