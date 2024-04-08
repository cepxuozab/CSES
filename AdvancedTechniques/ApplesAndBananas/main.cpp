#include <vector>
#include <complex>
#include <cmath>
#include <iostream>
#include <numbers>

using std::numbers::pi;

using complex = std::complex<double>;

auto cis(double theta) -> complex { return complex{std::cos(theta), std::sin(theta)}; }

auto omega(int n, int k) -> complex { return cis(pi * 2 * k / n); }

template <bool inv>
void fft_impl(std::vector<complex>& v) {
    int N = std::ssize(v);
    if (N == 1) return;

    int n = N >> 1;
    std::vector<complex> v0(n), v1(n);
    for (int i = 0; i < n; i++) {
        v0[i] = v[i << 1];
        v1[i] = v[i << 1 | 1];
    }

    fft_impl<inv>(v0), fft_impl<inv>(v1);

    for (int k = 0; k < n; k++) {
        complex w;
        if constexpr (inv) w = omega(N, -k);
        else w = omega(N, k);
        v[k] = v0[k] + w * v1[k];
        v[k + n] = v0[k] - w * v1[k];
    }
}

auto fft(std::vector<complex> a, std::vector<complex> b) -> std::vector<complex> {
    fft_impl<false>(a), fft_impl<false>(b);
    for (unsigned i = 0; i < std::size(a); i++)
        a[i] *= b[i];
    fft_impl<true>(a);
    for (auto& x : a) x /= std::size(a);
    return a;
}

auto main() -> int {
    int k, n, m;
    std::cin >> k >> n >> m;
    int sz = 2 * k;
    if (__builtin_popcount(sz) != 1) sz = 1 << (std::__lg(sz) + 1);
    std::vector<complex> a(sz, complex{0, 0}), b(sz, complex{0, 0});
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        a[x] += 1;
    }
    for (int i = 0; i < m; i++) {
        int x;
        std::cin >> x;
        b[x] += 1;
    }
    a = fft(a, b);
    for (int i = 2; i <= 2 * k; i++) {
        std::cout << (long) std::round(a[i].real()) << ' ';
    }
}