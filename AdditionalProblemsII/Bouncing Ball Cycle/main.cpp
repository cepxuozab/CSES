#include <iostream>
#include <numeric>
#include <cstdint>

auto main()->int{
    std::cin.tie(0)->sync_with_stdio(0);
    int T; std::cin >> T;
    while (T--) [&]() {
            int64_t N, M;  std::cin >> N >> M;
            N--, M--;
            int64_t ans1 = 2 *  std::lcm(N, M);
            int64_t g = 2 *  std::gcd(N, M);
            int64_t cnt_mod_M_lo = (M % g == 0 ? M / g : M / g + 1) - 1;
            int64_t cnt_mod_M_hi = M / g;
            int64_t cnt_mod_N_lo = (N % g == 0 ? N / g : N / g + 1) - 1;
            int64_t cnt_mod_N_hi = N / g;
            int64_t sub = (cnt_mod_M_lo * cnt_mod_N_lo + cnt_mod_M_hi * cnt_mod_N_hi);
            int64_t ans2 = 1 + ans1 / 2 - sub;
            std::cout << ans1 << " " << ans2 << '\n';
        }();
}
