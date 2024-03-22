/*****************************************************************//**
 * \file   main.cpp
 * \brief  Hotel Queries
 * 
 * \author CEPXUOZAB
 * \date   17 January 2024 
 * \link   https://cses.fi/problemset/task/1143/
 *********************************************************************/
#include <iostream>
#include <vector>

static auto const FastIo = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();


class SegmentTree {
    std::vector<int> data_;
    std::vector<int> tree_;

public:
    SegmentTree(std::vector<int> data) : data_(std::move(data)) {
        tree_.resize(4 * data_.size());
        build(0, 0, data_.size());
    }

    int update(int x) { return tree_[0] >= x ? update(0, 0, data_.size(), x) + 1 : 0; }

private:
    void build(int k, int l, int r) {
        if (r - l == 1)
            tree_[k] = data_[l];
        else {
            int m = (l + r) / 2;
            int k1 = k * 2 + 1;
            int k2 = k * 2 + 2;
            build(k1, l, m);
            build(k2, m, r);
            tree_[k] = tree_[k1] > tree_[k2] ? tree_[k1] : tree_[k2];
        }
    }

    int update(int k, int l, int r, int x) {

        if (r - l == 1) {
            tree_[k] -= x;
            return l;
        }
        int m = (l + r) / 2;
        int k1 = k * 2 + 1;
        int k2 = k * 2 + 2;
        int ans = tree_[k1] >= x ? update(k1, l, m, x) : update(k2, m, r, x);
        tree_[k] = tree_[k1] > tree_[k2] ? tree_[k1] : tree_[k2];
        return ans;
    }
};

int main() {
    int n;
    int m;
    std::cin >> n >> m;
    std::vector<int> data(n);
    for (int &elem: data) {
        std::cin >> elem;
    }
    auto tree = SegmentTree(data);
    for (int i = 0; i < m; ++i) {
        int x;
        std::cin >> x;
        std::cout << tree.update(x) << ' ';
    }
    return 0;
}
