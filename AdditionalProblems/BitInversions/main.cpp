#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

class SegTree {
    struct Node {
        int mx{};
        std::array<int, 2> left{};
        std::array<int, 2> right{};
    };

    auto Operation(Node const &lhs, Node const &rhs, int l, int r) -> Node;

    int n_;
    std::string &str_;
    std::vector<Node> segTree;
public:
    SegTree(int n, std::string &str) : n_(n), str_(str), segTree(4ULL * n) {}

    void Update(int pos) {
        UpdateImpl(pos, 1, 1, n_);
    }

    [[nodiscard]] auto GetMax() const {
        return segTree[1].mx;
    }

private:
    void UpdateImpl(int p, int u, int tl, int tr);
};

auto main() -> int {
    std::string str;
    std::cin >> str;
    int n = static_cast<int>(str.length());
    str = "^" + str;
    SegTree segTree(static_cast<int>(str.size()), str);
    for (int i = 1; i <= n; ++i) {
        segTree.Update(i);
    }
    int m;
    std::cin >> m;
    for (int i = 0; i < m; ++i) {
        int pos;
        std::cin >> pos;
        str[pos] = (str[pos] == '0' ? '1' : '0');
        segTree.Update(pos);
        std::cout << segTree.GetMax() << ' ';
    }
}

auto SegTree::Operation(const SegTree::Node &lhs, const SegTree::Node &rhs, int l, int r) -> SegTree::Node {
    int len = (r + l) / 2 - l + 1;
    int len2 = (r - l + 1) - len;
    Node result;
    result.mx = std::max({
                                 lhs.mx,
                                 rhs.mx,
                                 lhs.right[0] + rhs.left[0],
                                 lhs.right[1] + rhs.left[1]
                         });
    for (int k = 0; k < 2; k++) {
        result.left[k] = (lhs.left[k] == len ? len + rhs.left[k] : lhs.left[k]);
        result.right[k] = (rhs.right[k] == len2 ? len2 + lhs.right[k] : rhs.right[k]);
    }
    return result;
}

void SegTree::UpdateImpl(int p, int u, int tl, int tr) {
    if (tl == tr) {
        segTree[u].mx = 1;
        int k = str_[p] == '0' ? 0 : 1;
        segTree[u].left[k] = segTree[u].right[k] = 1;
        segTree[u].left[k ^ 1] = segTree[u].right[k ^ 1] = 0;
        return;
    }
    int mid = (tl + tr) / 2;
    if (p <= mid) {
        UpdateImpl(p, 2 * u, tl, mid);
    } else {
        UpdateImpl(p, 2 * u + 1, mid + 1, tr);
    }
    segTree[u] = Operation(segTree[2ULL * u], segTree[2ULL * u + 1], tl, tr);
}
