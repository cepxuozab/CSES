#include <iostream>
#include <cmath>

long long tri(long long x) {
    return (x * (x + 1)) >> 1;
}

bool is_tri(long long x) {
    return tri(sqrt(2 * x)) == x;
}

void solve(long long n) {
    if (is_tri(n)) {
        std::cout << "1\n";
        return;
    }
    bool can_split = false;
    for (long long i = 1;; i++) {
        auto tt = tri(i);
        if (tt > (n + 1) / 2) break;
        if (is_tri(n - tt)) {
            can_split = true;
            break;
        }
    }
    if (can_split) std::cout << "2\n";
    else std::cout << "3\n";

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        long long n;
        std::cin >> n;
        solve(n);
    }
}