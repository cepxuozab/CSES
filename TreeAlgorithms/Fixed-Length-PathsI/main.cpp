#include <iostream>
#include <map>
#include <vector>

using namespace std;


int max_depth;

vector<vector<int>> G;
int k;
long long ans;

map<int, int> dfs(int v, int p, int d = 0) {
    map<int, int> sum;
    sum[d]++;
    for (int u: G[v]) {
        if (u == p)
            continue;
        map<int, int> curr = dfs(u, v, d + 1);
        if (curr.size() > sum.size())
            swap(curr, sum);
        for (auto x: curr)
            if (sum.find(k + 2 * d - x.first) != sum.end())
                ans += (long long) sum[k + 2 * d - x.first] * (long long) x.second;
        for (auto x: curr)
            sum[x.first] += x.second;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n >> k;
    G.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1, 0);
    cout << ans;
}
