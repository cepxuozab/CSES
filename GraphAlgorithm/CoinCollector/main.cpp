#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
#include <cstdint>

[[maybe_unused]] static auto const FastIo = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

auto main() -> int {
    int n;
    int m;
    std::cin >> n >> m;
    std::vector<int> coins(n);
    for (int &coin: coins) {
        std::cin >> coin;
    }
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
    }
    std::vector<int> val(n + 1, -1);
    std::vector<int> compidx(n + 1, -1);
    std::vector<int64_t> tots(n + 1);
    std::vector<int> stk;
    int curind = 0;
    int ncomps = 0;
    std::function<void(int)> dfs = [&](int cur) {
        val[cur] = curind++;
        int mi = val[cur];
        stk.push_back(cur);
        for (int nxt: adj[cur]) {
            if (compidx[nxt] != -1)
                continue;
            if (val[nxt] == -1)
                dfs(nxt);
            mi = std::min(mi, val[nxt]);
        }
        if (mi == val[cur]) {
            int v;
            do {
                v = stk.back();
                stk.pop_back();
                tots[ncomps] += coins[v];
                compidx[v] = ncomps;
            } while (v != cur);
            ncomps++;
        }
        val[cur] = mi;
    };
    for (int i = 0; i < n; i++) {
        if (val[i] == -1) {
            dfs(i);
        }
    }
    std::vector<std::vector<int>> cadj(n + 1);

    for (int v = 0; v < n; v++) {
        for (int nxt: adj[v]) {
            int a = compidx[v];
            int b = compidx[nxt];
            if (a != b) {
                cadj[a].push_back(b);
            }
        }
    }
    std::vector<int64_t> dp(n + 1);
    std::function<int64_t(int)> dfs_best = [&](int cur) {
        if (!dp[cur]) {
            for (int nxt: cadj[cur]) {
                dp[cur] = std::max(dp[cur], dfs_best(nxt));
            }
            dp[cur] += tots[cur];
        }
        return dp[cur];
    };
    int64_t answer = 0;
    for (int i = 0; i < ncomps; i++) {
        answer = std::max(answer, dfs_best(i));
    }
    std::cout << answer << '\n';

    return 0;
}
