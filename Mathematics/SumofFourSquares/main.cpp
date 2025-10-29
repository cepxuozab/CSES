#include <iostream>
#include <cmath>

void solve(int n) {
    for (int a = 0; a * a <= n; ++a) {
        int a2 = a * a;
        for (int b = a; a2 + b * b <= n; ++b) {
            int b2 = b * b;
            for (int c = b; a2 + b2 + c * c <= n; ++c) {
                int c2 = c * c;
                int rem = n - a2 - b2 - c2;
                int d = sqrt(rem);
                if (d * d == rem) {
                    std::cout << a << " " << b << " " << c << " " << d << "\n";
                    return;
                }
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t, n;
    std::cin >> t;
    while (t--) {
        std::cin >> n;
        solve(n);
    }
}