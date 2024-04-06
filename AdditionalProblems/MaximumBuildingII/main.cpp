#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > ans;
vector<int> p, siz, alive;

auto root(int a) -> int { return a == p[a] ? a : p[a] = root(p[a]); }

void merge(int a, int b, int len) {
    a = root(a), b = root(b);
    if (a == b) return;

    ans[len][siz[a]]--;
    ans[len][siz[b]]--;

    p[b] = a;
    siz[a] += siz[b];

    ans[len][siz[a]]++;
}

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    p.resize(m), siz.resize(m), alive.resize(m);
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    ans.assign(n + 1, vector<int>(m + 1, 0));
    vector<int> nx(m, n);
    for (int r1 = n - 1; r1 >= 0; r1--) {
        vector<vector<int> > e(n + 1);
        for (int c = 0; c < m; c++) p[c] = c, siz[c] = 1, alive[c] = false;

        for (int c = 0; c < m; c++) {
            if (s[r1][c] == '*') nx[c] = r1;
            e[nx[c] - r1].push_back(c);
        }

        for (int len = n - r1; len >= 0; len--) {
            for (int j: e[len]) {
                alive[j] = true;
                if (siz[j] == 1) ans[len][1]++;

                if (j && alive[j - 1]) merge(j - 1, j, len);
                if (j + 1 < m && alive[j + 1]) merge(j + 1, j, len);
            }
        }
    }
    for (int r = n; r > 0; r--) {
        for (int c = 0; c <= m; c++) ans[r - 1][c] += ans[r][c];
    }

    for (int r = 1; r <= n; r++) {
        for (int c = m; c > 0; c--) ans[r][c - 1] += ans[r][c];
        for (int c = m; c > 0; c--) ans[r][c - 1] += ans[r][c];

        for (int c = 1; c <= m; c++) cout << ans[r][c] << " \n"[c == m];
    }
    return 0;
}