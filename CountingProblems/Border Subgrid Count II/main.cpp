#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<string> a(n);
    for (string &s: a) cin >> s;

    vector<long long> res(k);
    for (int imin = 0; imin < n; imin++) {
        vector<int> ok(n, 1);
        for (int imax = imin; imax < n; imax++) {
            auto same = [&](int j) { return a[imin][j] == a[imax][j]; };
            for (int jmin = 0; jmin < n; jmin++) {
                if (same(jmin) &&
                    (jmin == 0 || a[imin][jmin - 1] != a[imin][jmin] || a[imax][jmin - 1] != a[imin][jmin])) {
                    int count = 0;
                    for (int jmax = jmin; jmax < n && same(jmax) && a[imin][jmax] == a[imin][jmin]; jmax++) {
                        count += ok[jmax];
                    }
                    res[a[imin][jmin] - 'A'] += count * (count + 1) / 2;
                }
                if (!same(jmin)) ok[jmin] = 0;
            }
        }
    }
    for (auto x: res) cout << x << '\n';
}