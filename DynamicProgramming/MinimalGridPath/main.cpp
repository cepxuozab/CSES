#include <bits/stdc++.h>
using namespace std;

struct PairHash {
    auto operator()(const pair<int,int>& p) const noexcept -> size_t {
        // простое хеширование: x << 16 ^ y
        // (подходит при n <= 3000, так как координаты < 2^12)
        return ((size_t)p.first << 16) ^ p.second;
    }
};

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    string ans;
    unordered_set<pair<int,int>, PairHash> cur, next;
    cur.insert({0,0});
    ans.push_back(grid[0][0]);

    while (!cur.count({n-1,n-1})) {
        char best = 'Z' + 1;

        // ищем минимальную букву на следующем шаге
        for (auto [x,y] : cur) {
            if (x+1 < n) best = min(best, grid[x+1][y]);
            if (y+1 < n) best = min(best, grid[x][y+1]);
        }
        ans.push_back(best);

        next.clear();
        for (auto [x,y] : cur) {
            if (x+1 < n && grid[x+1][y] == best) next.insert({x+1,y});
            if (y+1 < n && grid[x][y+1] == best) next.insert({x,y+1});
        }

        cur.swap(next);
    }

    cout << ans << "\n";
}
