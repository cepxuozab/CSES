#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];

    // pos в массиве b
    unordered_map<int, int> pos_b;
    for (int i = 0; i < m; ++i) pos_b[b[i]] = i;

    // преобразуем a в массив индексов по b
    vector<int> c;
    for (int x: a) {
        if (pos_b.count(x)) c.push_back(pos_b[x]);
    }

    // LIS по массиву c
    int sz = c.size();
    vector<int> dp, idx, parent(sz, -1);
    for (int i = 0; i < sz; ++i) {
        int x = c[i];
        auto it = lower_bound(dp.begin(), dp.end(), x);
        int pos = it - dp.begin();
        if (pos == (int) dp.size()) {
            dp.push_back(x);
            idx.push_back(i);
        } else {
            dp[pos] = x;
            idx[pos] = i;
        }
        if (pos > 0) parent[i] = idx[pos - 1];
    }

    // восстановим последовательность
    vector<int> lis;
    int p = idx.back();
    while (p != -1) {
        lis.push_back(a[p]);
        p = parent[p];
    }
    reverse(lis.begin(), lis.end());

    cout << lis.size() << "\n";
    for (size_t i = 0; i < lis.size(); ++i) {
        if (i) cout << " ";
        cout << lis[i];
    }
    cout << "\n";
}
