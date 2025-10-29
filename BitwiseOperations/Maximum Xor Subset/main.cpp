#include <iostream>
#include <vector>
#include <algorithm>

const int B = 30;

int reduce(const std::vector<int> &base, int x) {
    int n = (int) base.size();
    for (int cur_row = 0; cur_row < n; cur_row++) {
        if (x == 0) return 0;
        x = std::min(x ^ base[cur_row], x);
    }
    return x;
}

std::vector<int> Gau(const std::vector<int> v) {
    int n = (int) v.size();
    std::vector<int> base;
    base.reserve(std::min((int) v.size(), B));
    for (int cur_row = 0; cur_row < n; cur_row++) {
        int val = reduce(base, v[cur_row]);
        if (val) base.push_back(val);
    }
    return base;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; i++) std::cin >> v[i];
    std::ranges::sort(v);
    auto const base = Gau(v);
    int mask = 0;
    for (auto x: base) {
        mask = std::max(mask, mask ^ x);
    }

    std::cout << mask << std::endl;
}
