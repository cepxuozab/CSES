#include <array>
#include <iostream>
#include <vector>
#include <string>
#include <string_view>

const int ALPHABET = 26;

struct Node {
    int len{0}, link{-1};
    std::array<int, ALPHABET> child;

    Node() { child.fill(-1); }
};

class Dawg {
    std::vector<Node> tree;
    int sz = 1, last = 0;
public:
    Dawg(std::string_view str = {}) {
        tree.emplace_back();
        for (char ch: str) {
            Add(ch);
        }
    }

    [[nodiscard]] auto GetNodes() const {
        return tree;
    }

private:
    void Add(char ch) {
        int idx = static_cast<int>(static_cast<unsigned char>(ch) - 'a');
        int cur = sz++;
        tree.emplace_back();
        tree[cur].len = tree[last].len + 1;
        tree[last].child[idx] = cur;
        int p = tree[last].link;
        while (p != -1 && tree[p].child[idx] == -1) {
            tree[p].child[idx] = cur;
            p = tree[p].link;
        }
        if (p == -1) {
            tree[cur].link = 0;
        } else {
            int q = tree[p].child[idx];
            if (tree[q].len == tree[p].len + 1) {
                tree[cur].link = q;
            } else {
                tree.push_back(tree[q]);
                tree.back().len = tree[p].len + 1;
                while (p != -1 && tree[p].child[idx] == q) {
                    tree[p].child[idx] = sz;
                    p = tree[p].link;
                }
                tree[q].link = tree[cur].link = sz;
                sz++;
            }
        }
        last = cur;

    }
};

auto main() -> int {
    std::string str;
    std::cin >> str;
    auto const dawg = Dawg(str);
    auto const &nodes = dawg.GetNodes();
    int k;
    std::cin >> k;
    for (int i = 0; i < k; ++i) {
        std::string pattern;
        std::cin >> pattern;
        int cur = 0;
        for (char ch: pattern) {
            int idx = static_cast<int>(static_cast<unsigned char>(ch) - 'a');
            cur = nodes[cur].child[idx];
            if (cur == -1) break;
        }
        std::cout << (cur == -1 ? "NO" : "YES") << '\n';

    }
}