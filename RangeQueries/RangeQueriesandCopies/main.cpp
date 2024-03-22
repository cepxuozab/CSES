#include <iostream>
#include <vector>

static auto const fastest = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

struct Node {
    int l, r;
    long long val;

    Node(int l, int r, long long val)
            : l(l), r(r), val(val) {
    }
};

std::vector<Node> T;
std::vector<int> root;

auto build(int L, int R, std::vector<int> &x) -> int;

auto update(int i, int L, int R, int w, int val) -> int;

auto query(int i, int L, int R, int lo, int hi) -> long long;

auto main() -> int {

    int n;
    int q;
    std::cin >> n >> q;
    std::vector<int> x(n);
    for (int &i: x) {
        std::cin >> i;
    }
    root.push_back(build(0, n, x));
    while ((q--) != 0) {
        int type;
        int k;
        std::cin >> type >> k;
        k--;
        int const value = root[k];
        if (type == 1) {
            int a;
            int b;
            std::cin >> a >> b;
            root[k] = update(value, 0, n, a - 1, b);
        } else if (type == 2) {
            int a;
            int b;
            std::cin >> a >> b;
            std::cout << query(value, 0, n, a - 1, b) << '\n';
        } else if (type == 3) {
            root.push_back(value);
        }
    }
    return 0;
}

auto build(int L, int R, std::vector<int> &x) -> int {
    if (R - L == 1) {
        T.emplace_back(0, 0, x[L]);
        return static_cast<int>(T.size()) - 1;
    }
    int M = (L + R) / 2;
    int ll = build(L, M, x);
    int rr = build(M, R, x);
    T.emplace_back(ll, rr, T[ll].val + T[rr].val);
    return static_cast<int>(T.size()) - 1;
}

auto update(int i, int L, int R, int w, int val) -> int {
    if (R - L == 1) {
        T.emplace_back(0, 0, val);
        return static_cast<int>(T.size()) - 1;
    }
    int M = (L + R) / 2;
    int ll = T[i].l;
    int rr = T[i].r;
    if (w < M) {
        ll = update(T[i].l, L, M, w, val);
    } else {
        rr = update(T[i].r, M, R, w, val);
    }
    T.emplace_back(ll, rr, T[ll].val + T[rr].val);
    return static_cast<int>(T.size()) - 1;
}

auto query(int i, int L, int R, int lo, int hi) -> long long {
    if (lo <= L && hi >= R) {
        return T[i].val;
    }
    if (lo >= R || hi <= L) {
        return 0;
    }
    int M = (L + R) / 2;
    return query(T[i].l, L, M, lo, hi)
           + query(T[i].r, M, R, lo, hi);
}
