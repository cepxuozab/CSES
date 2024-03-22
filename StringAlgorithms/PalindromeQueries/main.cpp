#include <string>
#include <iostream>
#include <cstdint>
#include <vector>

const int64_t B = 32767, M = 1e9 + 7;

class SegTree {
    struct Node {
        int64_t hv{}, rhv{};
    };

    struct Pow {
        Pow(unsigned n) : _pow(n + 2) {

            _pow[0] = 1;
            for (unsigned i = 1; i <= n; i++)
                _pow[i] = _pow[i - 1] * B % M;
            revpow = {_pow.rbegin(), _pow.rend()};
        }

        std::vector<int64_t> _pow, revpow;
    };

    std::vector<Node> tree;
    Pow power;
public:
    explicit SegTree(unsigned n) : tree(n << 2), power(n) {}

    void Update(int id, int l, int r, int k, char c) {
        if (l > k || r < k)
            return;
        if (l == r) {
            tree[id].hv = static_cast<int64_t>(static_cast<unsigned char>(c)) * power._pow[l] % M;
            tree[id].rhv = static_cast<int64_t>(static_cast<unsigned char>(c)) * power.revpow[l] % M;
            return;
        }
        int mid = (l + r) / 2;
        Update(id * 2 + 1, l, mid, k, c);
        Update(id * 2 + 2, mid + 1, r, k, c);
        tree[id].hv = (tree[id * 2 + 1].hv + tree[id * 2 + 2].hv) % M;
        tree[id].rhv = (tree[id * 2 + 1].rhv + tree[id * 2 + 2].rhv) % M;
    }


    [[nodiscard]] auto Check(int s, int e, int n) const -> bool {
        auto res = query(0, 1, n, s, e);
        res.hv *= power._pow[n - s + 1];
        res.hv %= M;
        res.rhv *= power._pow[e];
        res.rhv %= M;
        return res.hv == res.rhv;
    }

private:
    [[nodiscard]] auto query(int id, int l, int r, int ql, int qr) const -> Node {
        if (r < ql || l > qr)
            return {0, 0};
        if (l >= ql && r <= qr)
            return tree[id];
        int mid = (l + r) / 2;
        auto lres = query(id * 2 + 1, l, mid, ql, qr);
        auto rres = query(id * 2 + 2, mid + 1, r, ql, qr);
        Node res;
        res.hv = (lres.hv + rres.hv) % M;
        res.rhv = (lres.rhv + rres.rhv) % M;
        return res;
    }
};

auto main() -> int {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned n, q;
    std::cin >> n >> q;
    SegTree tree(n);
    std::string str;
    std::cin >> str;
    for (unsigned i = 0; i < n; i++)
        tree.Update(0, 1, n, i + 1, str[i]);
    for (unsigned j = 0; j < q; ++j) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int k;
            char c;
            std::cin >> k >> c;
            tree.Update(0, 1, n, k, c);
        } else {
            int l, r;
            std::cin >> l >> r;
            tree.Check(l, r, n) ? puts("YES") : puts("NO");
        }
    }

}