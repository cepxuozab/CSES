#include <iostream>
#include <vector>


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int bit = 0; (1 << bit) < n; ++bit) {
        for (int i = 0; i < n; ++i) {
            if (i >> bit & 1) {
                a[i] ^= a[i ^ (1 << bit)];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << ' ';
    }

}
