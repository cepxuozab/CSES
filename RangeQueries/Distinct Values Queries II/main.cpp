#include <iostream>
#include <vector>
#include <set>
#include <map>

const int INF = 1'000'000'007;

struct SegTree {
    int n;
    std::vector<int> tree;

    SegTree(int _n) {
        n = 1;
        while (n < _n)
            n *= 2;
        tree.assign(2 * n, INF);
    }

    void upd(int i, int x) {
        i += n;
        tree[i] = x;
        for (i /= 2; i >= 1; i /= 2) {
            tree[i] = std::min(tree[2 * i], tree[2 * i + 1]);
        }
    }

    int qry(int l, int r) {
        int res = INF;
        for (l += n, r += n; l <= r; l /= 2, r /= 2) {
            if (l % 2 == 1)
                res = std::min(res, tree[l++]);
            if (r % 2 == 0)
                res = std::min(res, tree[r--]);
        }
        return res;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n);
    for (int &val: a)
        std::cin >> val;

    std::map<int, std::set<int>> mp;
    for (int i = 0; i < n; ++i)
        mp[a[i]].insert(i);

    SegTree st(n);
    for (const auto &[value, indices]: mp) {
        auto it = indices.begin();
        while (std::next(it) != indices.end()) {
            st.upd(*it, *std::next(it));
            ++it;
        }
    }

    while (q--) {
        int t;
        std::cin >> t;
        if (t == 1) {
            int k, u;
            std::cin >> k >> u;
            --k;

            // Remove old connections
            std::set<int> &old_set = mp[a[k]];
            auto it = old_set.find(k);
            if (it != old_set.begin()) {
                auto prev_it = std::prev(it);
                if (std::next(it) == old_set.end()) {
                    st.upd(*prev_it, INF);
                } else {
                    st.upd(*prev_it, *std::next(it));
                }
            }
            old_set.erase(it);
            if (old_set.empty()) {
                mp.erase(a[k]);
            }

            a[k] = u;
            std::set<int> &new_set = mp[a[k]];
            auto new_it = new_set.insert(k).first;

            if (std::next(new_it) == new_set.end()) {
                st.upd(*new_it, INF);
            } else {
                st.upd(*new_it, *std::next(new_it));
            }

            if (new_it != new_set.begin()) {
                st.upd(*std::prev(new_it), *new_it);
            }
        } else {
            int l, r;
            std::cin >> l >> r;
            --l;
            --r;
            std::cout << (st.qry(l, r) <= r ? "NO" : "YES") << '\n';
        }
    }

    return 0;
}