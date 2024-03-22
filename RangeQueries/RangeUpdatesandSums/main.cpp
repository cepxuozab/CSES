#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

class SegTree {
    int n;
    std::vector<int> arr;
    std::vector<int64_t> seg;
    std::vector<int64_t> addtag, settag;

public:
    explicit SegTree(std::vector<int> const& data);
    void Build() {
        Build(1, 1, n);
    }
    auto Query(int ql, int qr) -> int64_t {
        return Query(1, 1, n, ql, qr);
    }
    void Add(int ql, int qr, int val) {
        Add(1, 1, n, ql, qr, val);
    }
    void Set(int ql, int qr, int val) {
        Setval(1, 1, n, ql, qr, val);
    }

private:
    static auto cl(int x) -> int {
        return x << 1;
    }
    static auto cr(int x) -> int {
        return (x << 1) + 1;
    }
    void Push(int id, int l, int r);
    void Pull(int id, int l, int r);
    void Build(int id, int l, int r);
    void Add(int id, int l, int r, int ql, int qr, int v);
    void Setval(int id, int l, int r, int ql, int qr, int v);
    auto Query(int id, int l, int r, int ql, int qr) -> int64_t;
};

auto main() -> int {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, q;
    std::cin >> n >> q;
    std::vector<int> data(n);
    for (auto& elem : data) {
        std::cin >> elem;
    }
    auto tree = SegTree(data);
    tree.Build();
    for (int i = 1, sta, l, r, val; i <= q; i++) {
        std::cin >> sta;
        if (sta == 1) {
            std::cin >> l >> r >> val;
            tree.Add(l, r, val);
        } else if (sta == 2) {
            std::cin >> l >> r >> val;
            tree.Set(l, r, val);
        } else if (sta == 3) {
            std::cin >> l >> r;
            std::cout << tree.Query(l, r) << '\n';
        }
    }
}
SegTree::SegTree(std::vector<int> const& data)
    : n(static_cast<int>(data.size()))
    , arr(data.size() + 1)
    , seg(4LL * data.size() + 5)
    , addtag(4LL * data.size() + 5)
    , settag(4LL * data.size() + 5) {
    std::ranges::copy(data, std::next(arr.begin()));
}

void SegTree::Push(int id, int l, int r) {
    if (settag[id] != 0) {
        seg[id] = settag[id] * (r - l + 1);
        if (l != r) {
            settag[cl(id)] = settag[id];
            settag[cr(id)] = settag[id];
            addtag[cl(id)] = addtag[cr(id)] = 0;
        }
        settag[id] = 0;
    }
    if (addtag[id] != 0) {
        seg[id] += addtag[id] * (r - l + 1);
        if (l != r) {
            addtag[cl(id)] += addtag[id];
            addtag[cr(id)] += addtag[id];
        }
        addtag[id] = 0;
    }
}

void SegTree::Pull(int id, int l, int r) {
    auto const mid = (l + r) >> 1;
    Push(cl(id), l, mid);
    Push(cr(id), mid + 1, r);
    auto const a = seg[cl(id)];
    auto const b = seg[cr(id)];
    seg[id] = a + b;
}

void SegTree::Build(int id, int l, int r) {
    if (l == r) {
        seg[id] = arr[l];
        return;
    }
    int mid = (l + r) >> 1;
    Build(cl(id), l, mid);
    Build(cr(id), mid + 1, r);
    Pull(id, l, r);
}

void SegTree::Add(int id, int l, int r, int ql, int qr, int v) {
    Push(id, l, r);
    if (ql <= l && r <= qr) {
        addtag[id] += v;
        return;
    }
    int mid = (l + r) >> 1;
    if (ql <= mid) Add(cl(id), l, mid, ql, qr, v);
    if (qr > mid) Add(cr(id), mid + 1, r, ql, qr, v);
    Pull(id, l, r);
}

void SegTree::Setval(int id, int l, int r, int ql, int qr, int v) {
    Push(id, l, r);
    if (ql <= l && r <= qr) {
        settag[id] = v;
        addtag[id] = 0;
        return;
    }
    int mid = (l + r) >> 1;
    if (ql <= mid) Setval(cl(id), l, mid, ql, qr, v);
    if (qr > mid) Setval(cr(id), mid + 1, r, ql, qr, v);
    Pull(id, l, r);
}

auto SegTree::Query(int id, int l, int r, int ql, int qr) -> int64_t {
    Push(id, l, r);
    if (ql <= l && r <= qr) {
        return seg[id];
    }
    int mid = (l + r) >> 1;
    int64_t ret = 0;
    if (ql <= mid) ret += Query(cl(id), l, mid, ql, qr);
    if (qr > mid) ret += Query(cr(id), mid + 1, r, ql, qr);
    return ret;
}