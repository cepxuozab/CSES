#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>

using namespace std;

using cd = complex<double>;
const double PI = acos(-1);

// Fast Fourier Transform
void fft(vector<cd> &a, bool invert) {
    int n = a.size();
    if (n == 1)
        return;

    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++) {
        a0[i] = a[2 * i];
        a1[i] = a[2 * i + 1];
    }
    fft(a0, invert);
    fft(a1, invert);

    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n / 2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n / 2] /= 2;
        }
        w *= wn;
    }
}

// Convolution using FFT
auto convolution(const vector<int> &a, const vector<int> &b) -> vector<int> {
    size_t n = 1;
    while (n < max(a.size(), b.size()))
        n *= 2;
    n *= 2;
    vector<cd> fa(n), fb(n);
    for (size_t i = 0; i < a.size(); i++)
        fa[i] = a[i];
    for (size_t i = 0; i < b.size(); i++)
        fb[i] = b[i];
    fft(fa, false);
    fft(fb, false);
    for (size_t i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(n);
    for (size_t i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}

auto countPairsWithDistance(const string &binary_str) -> vector<int> {
    int n = binary_str.size();
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        a[i] = binary_str[i] == '1' ? 1 : 0;
        b[i] = binary_str[n - i - 1] == '1' ? 1 : 0;
    }
    vector<int> result = convolution(a, b);
    //result.erase(result.begin());
    return result;
}

auto main() -> int {
    string binary_str;
    cin >> binary_str;
    vector<int> result = countPairsWithDistance(binary_str);
    for (size_t i = binary_str.size(); i < binary_str.size() * 2 - 1; i++)
        cout << result[i] << " ";

}