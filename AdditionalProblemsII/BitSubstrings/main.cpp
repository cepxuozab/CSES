#include <iostream>
#include <vector>
#include <complex>
#include <cstdint>
#include <numbers>
#include <utility>
#include <string>

using Complex = std::complex<double>;

void fft(std::vector<Complex> &a, int64_t n, bool invert) {
    n /= 2;
    if (n == 0) {
        return;
    }
    std::vector<Complex> a0(n), a1(n);
    for (int64_t i = 0; i < n; i++) {
        a0[i] = a[i * 2];
        a1[i] = a[i * 2 + 1];
    }
    fft(a0, n, invert);
    fft(a1, n, invert);
    Complex u = 1.0;
    Complex w = std::polar(1.0, invert ? -std::numbers::pi / n : std::numbers::pi / n);
    for (int64_t i = 0; i < n; i++) {
        a[i] = a0[i] + u * a1[i];
        a[i + n] = a0[i] - u * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n] /= 2;
        }
        u *= w;
    }
}

auto multiply(const std::vector<int64_t> &a, const std::vector<int64_t> &b) -> std::vector<int64_t> {
    std::vector<Complex> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int64_t n = 1;
    while (std::cmp_less(n, std::max(a.size(), b.size()) * 2)) {
        n *= 2;
    }
    fa.resize(n);
    fb.resize(n);
    fft(fa, n, false);
    fft(fb, n, false);
    for (int64_t i = 0; i < n; i++) {
        fa[i] *= fb[i];
    }
    fft(fa, n, true);
    std::vector<int64_t> result(n);
    for (int64_t i = 0; i < n; i++) {
        result[i] = llround(fa[i].real());
    }
    return result;
}

auto main() -> int {
    std::string S;
    std::cin >> S;
    int N = static_cast<int>(S.size());
    std::vector<int64_t> v(N + 1);
    v[0]++;
    for (int i = 0, c = 0; i < N; i++) {
        if (S[i] == '1') {
            c++;
        }
        v[c]++;
    }
    std::vector<int64_t> w(v.rbegin(), v.rend());
    auto ans = multiply(v, w);
    int64_t ans0 = 0;
    for (int i = 0; i <= N; i++) {
        ans0 += v[i] * (v[i] - 1) / 2;
    }
    std::cout << ans0 << ' ';
    for (int i = N - 1; i >= 0; i--) {
        std::cout << ans[i] << ' ';
    }

}
