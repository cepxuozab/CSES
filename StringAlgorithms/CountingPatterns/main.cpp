#include <iostream>
#include <string>
#include<queue>
#include <utility>
#include <vector>



struct Node {
    std::vector<Node *> children;
    Node *back, *out;
    int index;

    Node() : children(26) {
        back = out = nullptr;
        index = -1;
    }

    ~Node() {
        for (auto x: children) {
            delete x;
        }
    }
};


auto buildTrie(std::vector<std::string> const &words, std::vector<int> &dup) -> Node * {
    auto root = new Node();

    for (int i = 0; std::cmp_less(i, words.size()); ++i) {
        auto p = root;

        for (auto c: words[i]) {
            int key = c - 'a';
            if (!p->children[key]) {
                p->children[key] = new Node();
            }
            p = p->children[key];
        }

        if (p->index == -1) {
            p->index = i;
        } else {
            dup[i] = p->index;
        }
    }

    return root;
}

auto getNext(Node *x, int key) -> Node * {
    while (x->back && !x->children[key]) {
        x = x->back;
    }
    auto next = x->children[key];
    return next ? next : x;
}

void buildFSM(Node *root) {
    std::queue<Node *> q;

    for (auto x: root->children) {
        if (x) {
            x->back = root;
            q.push(x);
        }
    }

    while (!q.empty()) {
        auto u = q.front();
        q.pop();

        for (int i = 0; std::cmp_less(i, u->children.size()); ++i) {
            auto x = u->children[i];
            if (x) {
                x->back = getNext(u->back, i);
                x->out = x->back->index != -1 ? x->back : x->back->out;
                q.push(x);
            }
        }
    }
}

auto main() -> int {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;
    int m = static_cast<int>(s.size());

    int n;
    std::cin >> n;
    std::vector<std::string> words(n);
    for (auto &x: words) std::cin >> x;

    std::vector<int> dup(n, -1);
    auto root = buildTrie(words, dup);
    buildFSM(root);

    std::vector<int> ans(n);
    auto p = root;

    for (int i = 0; i < m; ++i) {
        p = getNext(p, s[i] - 'a');
        auto q = p->index != -1 ? p : p->out;

        while (q) {
            ++ans[q->index];
            q = q->out;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (dup[i] != -1) {
            ans[i] = ans[dup[i]];
        }
        std::cout << ans[i] << "\n";
    }

    delete root;

    return 0;
}