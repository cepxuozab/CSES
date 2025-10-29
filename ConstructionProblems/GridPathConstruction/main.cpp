#include <bits/stdc++.h>

using namespace std;

auto jo(int n, int m, int a, int b, int c, int d) -> bool {
    if (n > m) {
        swap(n, m);
        swap(a, b);
        swap(c, d);
    }
    int sa = (a + b) % 2, sb = (c + d) % 2;
    if (n % 2 && m % 2 && (sa || sb)) {
        return false;
    }
    if (b > d) {
        swap(a, c);
        swap(b, d);
    }
    if ((n % 2 == 0 || m % 2 == 0) && (sa == sb)) {
        return false;
    }

    if (a == c && b == d) {
        return (n == 1 && m == 1);
    }

    if (n == 1) {
        if (min(b, d) != 1 || max(b, d) != m) {
            return false;
        }
        return true;
    }

    if (n == 2) {
        if (b == d && b != 1 && b != m) {
            return false;
        }
    }
    if (n == 3) {
        if (a == 2 && b % 2 && b < d) {
            return false;
        }
        if (c == 2 && (m - d) % 2 == 0 && b < d) {
            return false;
        }
        if (m % 2 == 0 && (a + b) % 2 && d > b + 1) {
            return false;
        }
        if (m % 2 == 0 && (c + d) % 2 == 0 && d > b + 1) {
            return false;
        }
    }
    return true;
}

auto calc(int n, int m) -> vector<vector<pair<int, int> > > {
    vector<vector<pair<int, int> > > ans;
    if (n % 2 == 0) {
        vector<pair<int, int> > sor, sor2;
        for (int i = 1; i <= n; i++) {
            for (int j = 2; j <= m; j++) {
                int jj = (i % 2 ? j : m + 2 - j);
                sor.emplace_back(i, jj);
                sor2.emplace_back(i, m + 1 - jj);
            }
        }
        for (int i = n; i >= 1; i--) {
            sor.emplace_back(i, 1);
            sor2.emplace_back(i, m);
        }
        ans.push_back(sor);
        ans.push_back(sor2);
    } else {
        vector<pair<int, int> > sor;
        for (int i = 1; i <= n - 2; i++) {
            for (int j = 2; j <= m; j++) {
                int jj = (i % 2 ? j : m + 2 - j);
                sor.emplace_back(i, jj);
            }
        }
        for (int j = m; j >= 2; j--) {
            if (j % 2 == 0) {
                sor.emplace_back(n - 1, j);
                sor.emplace_back(n, j);
            } else {
                sor.emplace_back(n, j);
                sor.emplace_back(n - 1, j);
            }
        }
        for (int i = n; i >= 1; i--) {
            sor.emplace_back(i, 1);
        }
        for (int p = 0; p < 4; p++) {
            vector<pair<int, int> > uj;
            for (auto x: sor) {
                int a = x.first, b = x.second;
                if (p & 1) {
                    a = n + 1 - a;
                }
                if (p & 2) {
                    b = m + 1 - b;
                }
                uj.emplace_back(a, b);
            }
            ans.push_back(uj);
        }
    }
    return ans;
}

auto find_hamiltonian_paths(int n, int m) -> vector<vector<pair<int, int> > > {
    if (n % 2 && m % 2) {
        assert(false);
    }
    vector<vector<pair<int, int> > > ans;
    if (n == 1) {
        ans.emplace_back();
        for (int i = 1; i <= m; i++) {
            ans[0].emplace_back(1, i);
        }
        return ans;
    }
    if (m == 1) {
        ans.emplace_back();
        for (int i = 1; i <= n; i++) {
            ans[0].emplace_back(i, 1);
        }
    }
    vector<vector<pair<int, int> > > a = calc(n, m), b = calc(m, n);
    for (auto &x: a) {
        ans.push_back(x);
    }
    for (auto &x: b) {
        vector<pair<int, int> > rx;
        for (auto &y: x) {
            rx.emplace_back(y.second, y.first);
        }
        ans.push_back(rx);
    }
    return ans;
}

auto solve(int n, int m, int a, int b, int c, int d) -> vector<pair<int, int> > {
    vector<pair<int, int> > ans;
    if (!jo(n, m, a, b, c, d)) {
        ans.emplace_back(-1, -1);
        return ans;
    }

    int dist = abs(a - c) + abs(b - d);
    if (dist == 0) {
        ans.emplace_back(a, b);
        return ans;
    }
    if (dist == 1) {
        vector<vector<pair<int, int> > > sz = find_hamiltonian_paths(n, m);
        for (auto v: sz) {
            int si = static_cast<int>(v.size());
            assert(si == n * m);
            int pa = -1, pb = -1;
            for (int i = 0; i < si; i++) {
                if (v[i].first == a && v[i].second == b) {
                    pa = i;
                }
                if (v[i].first == c && v[i].second == d) {
                    pb = i;
                }
            }
            assert(pa != -1 && pb != -1);
            if ((pb + 1) % si == pa) {
                for (int i = pa; i < pa + si; i++) {
                    ans.push_back(v[i % si]);
                }
                return ans;
            }
            if ((pa + 1) % si == pb) {
                for (int i = pa; i > pa - si; i--) {
                    ans.push_back(v[(i + si) % si]);
                }
                return ans;
            }
        }
    }
    bool csere = false;
    if (a > c) {
        csere = 1 - csere;
        swap(a, c), swap(b, d);
    }
    for (int x = a; x < c; x++) {
        for (int y = 1; y <= m; y++) {
            int n2 = x, m2 = m, a2 = a, b2 = b, c2 = x, d2 = y;
            int n3 = n - x, m3 = m, a3 = 1, b3 = y, c3 = c - x, d3 = d;
            if (jo(n2, m2, a2, b2, c2, d2) && jo(n3, m3, a3, b3, c3, d3)) {
                if (csere) {
                    swap(n2, n3);
                    swap(m2, m3);
                    swap(a2, c3);
                    swap(b2, d3);
                    swap(c2, a3);
                    swap(d2, b3);
                }
                vector<pair<int, int> > aa = solve(n2, m2, a2, b2, c2, d2), bb = solve(n3, m3, a3, b3, c3, d3);
                for (auto xx: aa) {
                    int p = xx.first, q = xx.second;
                    if (csere) {
                        p += x;
                    }
                    ans.emplace_back(p, q);
                }
                for (auto xx: bb) {
                    int p = xx.first, q = xx.second;
                    if (!csere) {
                        p += x;
                    }
                    ans.emplace_back(p, q);
                }
                return ans;
            }
        }
    }
    if (b > d) {
        csere = 1 - csere;
        swap(a, c);
        swap(b, d);
    }
    for (int y = b; y < d; y++) {
        for (int x = 1; x <= n; x++) {
            int n2 = n, m2 = y, a2 = a, b2 = b, c2 = x, d2 = y;
            int n3 = n, m3 = m - y, a3 = x, b3 = 1, c3 = c, d3 = d - y;
            if (jo(n2, m2, a2, b2, c2, d2) && jo(n3, m3, a3, b3, c3, d3)) {
                if (csere) {
                    swap(n2, n3);
                    swap(m2, m3);
                    swap(a2, c3);
                    swap(b2, d3);
                    swap(c2, a3);
                    swap(d2, b3);
                }
                vector<pair<int, int> > aa = solve(n2, m2, a2, b2, c2, d2), bb = solve(n3, m3, a3, b3, c3, d3);
                for (auto xx: aa) {
                    int p = xx.first, q = xx.second;
                    if (csere) {
                        q += y;
                    }
                    ans.emplace_back(p, q);
                }
                for (auto xx: bb) {
                    int p = xx.first, q = xx.second;
                    if (!csere) {
                        q += y;
                    }
                    ans.emplace_back(p, q);
                }
                return ans;
            }
        }
    }
    if (csere) {
        swap(a, c);
        swap(b, d);
        csere = false;
    }
    bool rot = false, rot2 = false;
    if (n != 3) {
        swap(n, m);
        swap(a, c);
        swap(b, d);
        rot = true;
    }
    if (a > c) {
        swap(a, c);
        swap(b, d);
        csere = 1 - csere;
    }
    if (b < d) {
        rot2 = true;
        b = m + 1 - b;
        d = m + 1 - d;
    }
    vector<pair<int, int> > sor;
    for (int i = b; i >= 1; i--) {
        sor.emplace_back(1, i);
    }
    for (int i = 1; i < d; i++) {
        if (i % 2) {
            sor.emplace_back(2, i);
            sor.emplace_back(3, i);
        } else {
            sor.emplace_back(3, i);
            sor.emplace_back(2, i);
        }
    }
    sor.emplace_back(2, d);
    if (b > d) {
        sor.emplace_back(2, b);
    }
    for (int i = b + 1; i <= m; i++) {
        if ((m - i) % 2) {
            sor.emplace_back(2, i);
            sor.emplace_back(1, i);
        } else {
            sor.emplace_back(1, i);
            sor.emplace_back(2, i);
        }
    }
    for (int i = m; i >= d; i--) {
        sor.emplace_back(3, i);
    }

    int si = static_cast<int>(sor.size());
    assert(si == n * m);
    for (int i = 0; i < si; i++) {
        int x = sor[i].first, y = sor[i].second;
        if (rot2) {
            y = m + 1 - y;
        }
        if (rot) {
            swap(x, y);
        }
        sor[i] = {x, y};
    }
    if (csere) {
        reverse(sor.begin(), sor.end());
    }
    return sor;
}



auto main() -> int {
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int n, m, a, b, c, d;
        cin >> n >> m >> a >> b >> c >> d;
        vector<pair<int, int> > ans = solve(n, m, a, b, c, d);
        if (ans[0].first == -1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            int si = static_cast<int>(ans.size());
            for (int i = 1; i < si; i++) {
                int x = ans[i].first - ans[i - 1].first, y = ans[i].second - ans[i - 1].second;
                if (x == 1) {
                    cout << "D";
                }
                if (x == -1) {
                    cout << "U";
                }
                if (y == -1) {
                    cout << "L";
                }
                if (y == 1) {
                    cout << "R";
                }
            }
            cout << "\n";
        }
    }
    return 0;
}