#include <iostream>
#include <memory>
#include <vector>

static auto const fastest = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Tree {
    std::vector<int> tree;

public:
    Tree() = default;
    explicit Tree(int n) {
        size_t size = 1;
        while (size <= n) {
            size *= 2;
        }
        tree.resize(2 * size);
        build(0, 0, n);
    }
    void build(int idx, int left, int right) {
        if (right - left == 1) {
            tree[idx] = 1;
            return;
        }
        int const mid = (left + right) / 2;
        build(2 * idx + 1, left, mid);
        build(2 * idx + 2, mid, right);
        tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
    }

    auto query(int idx, int left, int right, int val) -> int {
        tree[idx]--;
        if (right - left == 1) {
            return right;
        }
        int const mid = (left + right) / 2;
        return tree[2 * idx + 1] >= val ? query(2 * idx + 1, left, mid, val)
                                        : query(2 * idx + 2, mid, right, val - tree[2 * idx + 1]);
    }
};

auto main() -> int {
    int n;
    std::cin >> n;
    auto segment = std::make_unique<Tree>(n);
    std::vector<int> list(n);
    for (int& i : list) {
        std::cin >> i;
    }
    for (int h = 0; h < n; ++h) {
        int pos;
        std::cin >> pos;
        auto idx = segment->query(0, 0, n, pos) - 1;
        std::cout << list[idx] << ' ';
    }
    std::cout << '\n';
}