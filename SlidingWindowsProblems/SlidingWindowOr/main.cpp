#include <iostream>
#include <vector>
#include <cstdint> // for std::int64_t

namespace {

    int solve_sliding_window_or(int K, const std::vector<int> &values) {
        const int n = static_cast<int>(values.size());

        std::vector<int> pre(n);
        std::vector<int> suf(n);

        for (int i = 0; i < n; ++i) {
            if (i % K == 0) {
                pre[i] = values[i];
            } else {
                pre[i] = pre[i - 1] | values[i];
            }
        }

        for (int i = n - 1; i >= 0; --i) {
            if (i % K == K - 1) {
                suf[i] = values[i];
            } else {
                suf[i] = suf[i + 1] | values[i];
            }
        }

        int xor_sum = 0;
        for (int i = 0; i <= n - K; ++i) {
            int l = i;
            int r = i + K - 1;
            int or_val = suf[l] | pre[r];
            xor_sum ^= or_val;
        }

        return xor_sum;
    }

} // namespace

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, K;
    std::cin >> N >> K;

    std::int64_t x, a, b, c; // ✅ Используем знаковый тип, как в оригинале
    std::cin >> x >> a >> b >> c;

    std::vector<int> values(N);
    for (int i = 0; i < N; ++i) {
        values[i] = static_cast<int>(x);
        x = (a * x + b) % c;
    }

    const int result = solve_sliding_window_or(K, values);

    std::cout << result << '\n';

    return 0;
}