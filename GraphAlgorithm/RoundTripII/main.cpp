#include <algorithm>
#include <iostream>
#include <memory>
#include <optional>
#include <vector>

static auto const FastIO = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Graph {
private:
    size_t size;
    std::vector<std::vector<int>> adj_list;
    std::vector<int> used;
    std::vector<int> ans;
    bool isSuccess = false;

public:
    Graph(size_t n)
        : size(n)
        , adj_list(n)
        , used(n, 0) {
    }
    void add(int a, int b) {
        a--;
        b--;
        adj_list[a].push_back(b);
    }
    auto get_answer() -> std::optional<std::vector<int>> {
        make_trip();
        if (!isSuccess) {
            return std::nullopt;
        }
        return ans;
    }

private:
    void make_trip() {
        for (size_t i = 0; i < size; i++) {
            if ((used[i] == 0) && dfs(i)) {
                isSuccess = true;
                return;
            }
        }
    }

    auto dfs(int i) -> bool {
        used[i] = 1;
        for (auto j : adj_list[i]) {
            if ((used[j] == 0) && dfs(j)) {
                if (ans.front() != ans.back()) {
                    ans.push_back(i);
                }
                return true;
            }
            if (used[j] == 1) {
                ans.push_back(j);
                ans.push_back(i);
                return true;
            }
        }
        used[i] = 2;
        return false;
    }
};

auto main() -> int {
    int n;
    int m;
    std::cin >> n >> m;
    auto grahp = std::make_unique<Graph>(n);
    while (m-- != 0) {
        int a;
        int b;
        std::cin >> a >> b;
        grahp->add(a, b);
    }
    auto result = grahp->get_answer();
    if (!result.has_value()) {
        std::cout << "IMPOSSIBLE\n";
        return 0;
    }
    auto ans = result.value();
    std::ranges::reverse(ans);
    std::cout << ans.size() << '\n';
    for (int i : ans) {
        std::cout << i + 1 << ' ';
    }
    std::cout << '\n';
}
