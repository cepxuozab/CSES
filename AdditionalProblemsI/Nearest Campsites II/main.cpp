#include <bits/stdc++.h>

using namespace std;

struct SuffixMin {
    map<int, int> m;

    void insert(int x, int val) {
        auto it = m.lower_bound(x);
        if (it != m.end() && it->second <= val) {
            return;
        }
        it = m.insert(it, {x, val});
        it->second = val;
        while (it != m.begin() && prev(it)->second >= val) {
            it = m.erase(prev(it));
        }
    }

    auto query(int x) -> int {
        auto it = m.lower_bound(x);
        if (it == m.end()) {
            return 1e9;
        }
        return it->second;
    }
};

auto main() -> int {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> x(n + m), y(n + m);
    for (int i = 0; i < n + m; i++) {
        cin >> x[i] >> y[i];
    }
    vector<int> idx(n + m);
    vector<int> dist(m, INT_MAX);
    iota(idx.begin(), idx.end(), 0);
    for (int k = 0; k < 4; k++) {
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return make_pair(-y[i], -x[i]) < make_pair(-y[j], -x[j]);
        });
        SuffixMin sm;
        for (int i: idx) {
            if (i < n) {
                sm.insert(x[i], x[i] + y[i]);
            } else {
                dist[i - n] = min(dist[i - n], sm.query(x[i]) - (x[i] + y[i]));
            }
        }
        for (int i = 0; i < n + m; i++) {
            x[i] = -x[i];
            if (k & 1) {
                y[i] = -y[i];
            }
        }
    }
    for (int i = 0; i < m; i++) {
        cout << dist[i] << " ";
    }
    cout << '\n';
    return 0;
}