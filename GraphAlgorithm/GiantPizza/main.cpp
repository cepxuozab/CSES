#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Pizza {
private:
    int n;
    std::vector<std::vector<int>> aa, bb;
    std::vector<int> cc, qq;
    int cnt = 0;

    void dfs(int i);

    void dfs1(int j, int c);

public:
    Pizza(int n_);

    void add(int up, int um, int vp, int vm);

    auto get_answer() -> std::string;
};

auto main() -> int {
    int n;
    int m;
    std::cin >> m >> n;
    auto pizza = std::make_unique<Pizza>(n);
    while (m-- != 0) {
        char ch;
        std::cin >> ch;
        bool uplus = ch == '+';
        int u;
        std::cin >> u;
        std::cin >> ch;
        bool vplus = ch == '+';
        int v;
        std::cin >> v;
        u--, v--;
        int up = u * 2 + (uplus ? 1 : 0);
        int um = u * 2 + (uplus ? 0 : 1);
        int vp = v * 2 + (vplus ? 1 : 0);
        int vm = v * 2 + (vplus ? 0 : 1);
        pizza->add(up, um, vp, vm);
    }
    std::cout << pizza->get_answer() << '\n';
}

Pizza::Pizza(int n_)
        : n(n_), aa(2LL * n_), bb(2LL * n_), cc(2LL * n_), qq(2LL * n_) {
}

void Pizza::add(int up, int um, int vp, int vm) {
    aa[um].push_back(vp);
    bb[vp].push_back(um);
    aa[vm].push_back(up);
    bb[up].push_back(vm);
}

void Pizza::dfs(int i) {
    if (cc[i] != 0) {
        return;
    }
    cc[i] = 1;
    auto adj = aa[i];
    for (int j: adj) {
        dfs(j);
    }
    qq[cnt++] = i;
}

void Pizza::dfs1(int j, int c) {
    if (cc[j] != 0) {
        return;
    }
    cc[j] = c;
    auto adj = bb[j];
    for (int i: adj) {
        dfs1(i, c);
    }
}

auto Pizza::get_answer() -> std::string {
    for (int i = 0; i < n * 2; i++) {
        if (cc[i] == 0) {
            dfs(i);
        }
    }
    cc.assign(cc.size(), 0);
    int c = 0;
    for (int h = n * 2 - 1; h >= 0; h--) {
        int j = qq[h];
        if (cc[j] == 0) {
            dfs1(j, ++c);
        }
    }
    std::string answer;
    for (int i = 0; i < n * 2; i += 2) {
        if (cc[i] == cc[i + 1]) {
            return "IMPOSSIBLE";
        }
        answer.append((cc[i] < cc[i + 1]) ? "+ " : "- ");
    }
    return answer;
}
