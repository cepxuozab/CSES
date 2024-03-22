#include <iostream>
#include <vector>
#include <deque>

using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

ll ans;
int N, K1, K2;
vector<vector<int>> g;

ll get_prefix(deque<int> &cnt, int p) {
    // NOTE: the preifx sum is counted in the reverse order
    // cnt[0] = a[0] + a[1] + ... + a[k]
    // cnt[1] = a[1] + a[2] + ... + a[k]
    if (p < 0) {
        return 0;
    } else if (p >= cnt.size() - 1) {
        return cnt[0];
    } else {
        return cnt[0] - cnt[p + 1];
    }
}

void merge(int u, deque<int> &cnt, deque<int> &a) {
    // cnt[i] denotes the number of nodes have the depth `i` rooted at u
    if (cnt.size() < a.size()) {
        swap(cnt, a);
    }
    for (int i = 0; i < (int) a.size() - 1; i++) {
        // compute each depth from prefix sum
        a[i] -= a[i + 1];
    }
    for (int i = 0; i < (int) a.size(); i++) {
        ans += (ll) a[i] * (get_prefix(cnt, K2 - i) - get_prefix(cnt, K1 - 1 - i));
    }
    for (int i = a.size() - 2; i >= 0; i--) {
        // compute prefix sum back
        a[i] += a[i + 1];
    }
    for (int i = 0; i < (int) a.size(); i++) {
        cnt[i] += a[i];
    }
}

deque<int> dfs(int u, int p) {
    deque<int> cnt{1};
    for (int v: g[u]) {
        if (v == p)
            continue;
        deque<int> a = dfs(v, u);
        // NOTE: add the all depths that rooted at node v by 1
        a.push_front(a.front());
        merge(u, cnt, a);
    }
    return cnt;
}

void solve() {
    cin >> N >> K1 >> K2;
    g.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, -1);
    cout << ans << "\n";
}

int main() {    
    ios_base::sync_with_stdio(0), cin.tie(0);
    solve();
    return 0;
}
