#include <iostream>
#include <vector>
#include <numeric>

struct DisjoinjSet {
    std::vector<int> sz, pai, te;

    DisjoinjSet(int n, int m) : sz(n + 1, 1), pai(n + 1), te(n + 1, m + 1) {
        std::iota(pai.begin(), pai.end(), 0);
    }

    auto find(int x) -> int {
        if (x == pai[x]) return x;
        return find(pai[x]);
    }

    void join(int a, int b, int t) {
        a = find(a), b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) std::swap(a, b);
        pai[b] = a;
        if (sz[a] == sz[b]) sz[a]++;
        te[b] = t;
    }

    auto query(int a, int b) -> int {
        int ans = 0;
        if (find(a) != find(b)) return -1;
        while (a != b) {
            if (te[a] > te[b]) {
                ans = te[b];
                b = pai[b];
            } else {
                ans = te[a];
                a = pai[a];
            }
        }
        return ans;
    }

};

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m, q, a, b;
    std::cin >> n >> m >> q;
    DisjoinjSet ds(n, m);

    for (int i = 1; i <= m; i++) {
        std::cin >> a >> b;
        ds.join(a, b, i);
    }
    for (int i = 0; i < q; i++) {
        std::cin >> a >> b;
        std::cout << ds.query(a, b) << '\n';
    }
    return 0;
}