#include <bits/stdc++.h>

using namespace std;
using ll = long long;

using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> &a, bool invert) {
    ll n = a.size();

    for (ll i = 1, j = 0; i < n; i++) {
        ll bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (ll len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (ll i = 0; i < n; i += len) {
            cd w(1);
            for (ll j = 0; j < len / 2; j++) {
                cd u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd &x: a)
            x /= n;
    }
}

auto multiply(vector<ll> const &a, vector<ll> const &b) -> vector<ll> {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < (int) a.size() + (int) b.size())
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (ll i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<ll> result(n);
    for (ll i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}

auto main() -> int {
    int n, m, i;
    cin >> n >> m;
    vector<ll> p(n), q(m);
    for (i = 0; i < n; i++)
        cin >> p[i];
    for (i = 0; i < m; i++)
        cin >> q[i];

    reverse(q.begin(), q.end());
    auto res = multiply(p, q);
    for (i = 0; i < n + m - 1; i++)
        cout << res[i] << " ";
}