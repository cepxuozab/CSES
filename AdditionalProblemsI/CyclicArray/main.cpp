#include <iostream>
#include <vector>
#include <cstdint>

auto main() -> int {
    int n;
    int64_t k;
    std::cin >> n >> k;
    std::vector<int> x(2LL * n);
    for (int i = 0; i < n; ++i) {
        std::cin >> x[i];
        x[i + n] = x[i];
    }
    int r = 0;
    int64_t sum = 0;
    std::vector<int> last(n);
    for (int l = 0; l < n; l++) {
        while (r < l + n && sum + x[r] <= k) {
            sum += x[r];
            r++;
        }
        last[l] = r % n;
        sum -= x[l];
    }
    int opt = 0;
    for (int i = 0; i < n; i++)
        opt = last[opt];

    int cnt = 1;
    sum = x[opt];
    for (int i = opt + 1; i < n + opt; i++) {
        if (sum + x[i] <= k) sum += x[i];
        else {
            sum = x[i];
            cnt++;
        }
    }
    std::cout << cnt;

}