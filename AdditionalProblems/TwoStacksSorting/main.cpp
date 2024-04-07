#include <iostream>
#include <vector>
#include <functional>


struct DSU {
    std::vector<int> pa;

    DSU(int n) {
        pa.resize(n);
        for (int i = 0; i < n; i++) {
            pa[i] = i;
        }
    }

    auto find(int v) -> int {
        return (pa[v] == v ? v : pa[v] = find(pa[v]));
    }

    void merge(int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            pa[std::min(u, v)] = std::max(u, v);
        }
    }
};

auto main() -> int {
    int n;
    std::cin >> n;
    std::vector<int> P(n), pos(n);
    for (int i = 0; i < n; i++) {
        std::cin >> P[i];
        P[i]--;
        pos[P[i]] = i;
    }

    int last = -1;
    std::vector<std::vector<int>> G(n);
    DSU D_jmp(n), D_nxt(n + 1);
    for (int i = 0; i < n; i++) {
        int p = pos[i];
        last = std::max(last, p);
        D_nxt.merge(p, p + 1);

        int pre = -1, cur = D_nxt.find(p);
        while (cur < last) {
            G[cur].push_back(p);
            G[p].push_back(cur);
            if (pre != -1) {
                D_jmp.merge(pre, cur);
            }
            pre = cur;
            cur = D_jmp.find(cur);
            cur = D_nxt.find(cur + 1);
        }
    }

    int ok = 1;
    std::vector<int> col(n, -1);
    std::function<void(int, int)> dfs = [&](int v, int c) {
        col[v] = c;
        for (int to: G[v]) {
            if (col[to] == -1) {
                dfs(to, !c);
            }
            ok &= (col[to] != col[v]);
        }
    };
    for (int i = 0; i < n; i++) {
        if (col[i] == -1) {
            dfs(i, 0);
        }
    }

    if (ok) {
        for (int i = 0; i < n; i++) {
            std::cout << col[i] + 1 << " \n"[i == n - 1];
        }
    } else {
        std::cout << "IMPOSSIBLE\n";
    }

}