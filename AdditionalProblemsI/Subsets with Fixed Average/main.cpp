#include <bits/stdc++.h>

using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a;
    cin >> n >> a;
    vector<int> x(n);
    for (int &v: x) cin >> v;

    int offset = 250 * n;
    int maxS = offset * 2 + 1;
    vector<int> dp(maxS, 0), next_dp(maxS, 0);
    dp[offset] = 1;  // пустое множество (сумма 0)

    for (int i = 0; i < n; ++i) {
        fill(next_dp.begin(), next_dp.end(), 0);
        int val = x[i] - a;
        for (int s = 0; s < maxS; ++s) {
            if (!dp[s]) continue;
            // не берём элемент
            (next_dp[s] += dp[s]) %= MOD;
            // берём элемент
            int t = s + val;
            if (t >= 0 && t < maxS)
                (next_dp[t] += dp[s]) %= MOD;
        }
        dp.swap(next_dp);
    }

    // вычитаем пустое множество
    cout << (dp[offset] - 1 + MOD) % MOD << "\n";
    return 0;
}