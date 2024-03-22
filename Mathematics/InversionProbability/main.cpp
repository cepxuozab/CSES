#include <iomanip>
#include <iostream>
#include <vector>

auto main() -> int {
    int n;
    std::cin >> n;
    std::vector<double> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    double ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double pair_prob = 0;
            for (int x = 1; x <= a[i]; x++) {
                pair_prob += (1 / a[i]) * (std::min(1.0, (x - 1) / a[j]));
            }
            ans += pair_prob;
        }
    }
    std::cout << std::setprecision(6) << std::fixed;
    std::cout << ans << "\n";
}
