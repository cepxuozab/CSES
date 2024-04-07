#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7, mx = 500;

auto mul(int x, int y) -> int {
    return (1LL * x * y) % mod;
}

auto main() -> int {
    vector<int> fact(mx + 1);
    vector<vector<int>> ncr(mx + 1, vector<int>(mx + 1, 0));
    fact[0] = 1, ncr[0][0] = 1;
    for (int i = 1; i <= mx; i++) {
        fact[i] = mul(fact[i - 1], i), ncr[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            ncr[i][j] = (ncr[i - 1][j - 1] + ncr[i - 1][j]) % mod;
        }
    }
    int n, num1 = 0, num2 = 0, c1 = 0, c2 = 0, c3 = 0, c4 = 0;
    cin >> n;
    vector<string> grid(n);
    vector<int> p1(n, -1), p2(n, -1);
    vector<bool> vis1(n, false), vis2(n, false);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 'A') p1[i] = j, vis1[j] = true, ++num1;
            if (grid[i][j] == 'B') p2[i] = j, vis2[j] = true, ++num2;
        }
    }
    num1 = n - num1, num2 = n - num2;
    for (int i = 0; i < n; i++) {
        c1 += p1[i] >= 0 && p2[i] == -1 && !vis2[p1[i]];
        c2 += p2[i] >= 0 && p1[i] == -1 && !vis1[p2[i]];
        c3 += !vis1[i] && !vis2[i];
        c4 += p1[i] == -1 && p2[i] == -1;
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= c1; j++) {
            for (int k = 0; k <= min(i - j, c2); k++) {
                int num = mul(mul(ncr[c1][j], ncr[c2][k]), mul(ncr[c3][i - j - k], ncr[c4][i - j - k]));
                if (num1 - k - (i - j - k) < 0) continue;
                if (num2 - j - (i - j - k) < 0) continue;
                num = mul(num, mul(fact[i - j - k], mul(fact[num1 - k - (i - j - k)], fact[num2 - j - (i - j - k)])));
                if (i & 1) ans = (ans - num + mod) % mod;
                else ans = (ans + num) % mod;
            }
        }
    }
    cout << ans << '\n';
}