#include <iostream>
#include <string>
#include <cstdint>
#include <vector>
#include <map>
#include <string_view>

struct SuffixAutomaton {
    struct Node {
        int len = 0, lnk = 0;
        std::map<char, int> nxt;
    };
    std::vector<Node> t;
    int last = 0;

    SuffixAutomaton(std::string_view s) {
        t.push_back({0, -1, {}});
        for (char c: s) add(c);
    }

    void add(char c) {
        int u = last;
        int v = static_cast<int>(std::size(t));
        t.push_back({t[u].len + 1, 0, {}});
        last = v;
        while (u >= 0 && !t[u].nxt.count(c)) {
            t[u].nxt[c] = v;
            u = t[u].lnk;
        }
        if (u == -1) return;
        int q = t[u].nxt[c];
        if (t[u].len + 1 == t[q].len) {
            t[v].lnk = q;
            return;
        }
        int cpy = static_cast<int>(std::size(t));
        t.push_back(t[q]);
        t[cpy].len = t[u].len + 1;
        while (u >= 0 && t[u].nxt[c] == q) {
            t[u].nxt[c] = cpy;
            u = t[u].lnk;
        }
        t[v].lnk = t[q].lnk = cpy;
    }
};

auto main() -> int {
    std::string s;
    std::cin >> s;
    SuffixAutomaton sa(s);
    int64_t res = 0;
    for (size_t i = 1; i < std::size(sa.t); i++) {
        res += sa.t[i].len - sa.t[sa.t[i].lnk].len;
    }
    std::cout << res << "\n";

}
