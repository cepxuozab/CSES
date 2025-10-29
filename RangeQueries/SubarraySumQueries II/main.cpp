#include <iostream>
#include <vector>
#include <algorithm>

[[maybe_unused]] const long long INF = (long long) 1e18;

struct State {
    long long sum, max_pref, max_suf, max_sub;
};

struct SegTree {
    int n;
    std::vector<State> tree;
    const State id = {0, 0, 0, 0};

    State cmb(const State &a, const State &b) {
        return {
                a.sum + b.sum,
                std::max(a.max_pref, a.sum + b.max_pref),
                std::max(b.max_suf, b.sum + a.max_suf),
                std::max({a.max_sub, b.max_sub, a.max_suf + b.max_pref})
        };
    }

    SegTree(int _n) {
        n = 1;
        while (n < _n)
            n *= 2;
        tree.assign(2 * n, id);
    }

    void upd(int i, const State &x) {
        tree[i += n] = x;
        for (i /= 2; i >= 1; i /= 2) {
            tree[i] = cmb(tree[2 * i], tree[2 * i + 1]);
        }
    }

    State qry(int l, int r) {
        l += n, r += n;
        State resl = id, resr = id;
        while (l <= r) {
            if (l % 2 == 1)
                resl = cmb(resl, tree[l++]);
            if (r % 2 == 0)
                resr = cmb(tree[r--], resr);
            l /= 2;
            r /= 2;
        }
        return cmb(resl, resr);
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;
    SegTree st(n);
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        int xp = std::max(0, x);
        st.upd(i, {x, (long long) xp, (long long) xp, (long long) xp});
    }

    while (q--) {
        int a, b;
        std::cin >> a >> b;
        --a;
        --b;
        std::cout << st.qry(a, b).max_sub << '\n';
    }

    return 0;
}