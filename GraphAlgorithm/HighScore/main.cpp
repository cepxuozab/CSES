#include <functional>
#include <iostream>
#include <stack>
#include <vector>

[[maybe_unused]] static auto const FastIo = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

auto Dfs(std::vector<bool>& changed, std::vector<std::vector<int>> const& g) -> bool {
    std::stack<int> s;
    s.emplace(g.size() - 1);
    std::vector<bool> visited(g.size(), false);
    while (!s.empty()) {
        int curr = s.top();
        s.pop();

        visited[curr] = true;

        if (changed[curr]) return false;

        for (auto i : g[curr]) {
            if (!visited[i]) {
                visited[i] = true;
                s.push(i);
            }
        }
    }

    return true;
}

auto HighScore(std::vector<std::tuple<int, int, int>> const& arr, int n) -> long long {
    std::vector<long long> distances(n + 1, 1LL << 40);
    distances[1] = 0;

    for (int i = 0; i < n - 1; ++i) {
        for (auto const& [v1, v2, w] : arr) {
            if (distances[v1] >= 1LL << 40) continue;

            if (distances[v1] + w < distances[v2]) distances[v2] = distances[v1] + w;
        }
    }

    std::vector<bool> changed(n + 1, false);
    std::vector<std::vector<int>> g(n + 1);

    for (auto const& [v1, v2, w] : arr) {
        if (distances[v1] >= 1LL << 40) continue;

        if (distances[v1] + w < distances[v2]) changed[v2] = true;

        g[v2].emplace_back(v1);
    }

    if (!Dfs(changed, g)) return -1;

    return -distances.back();
}

auto main() -> int {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::tuple<int, int, int>> arr(m);
    for (int i = 0; i < m; ++i) {
        int x, y, w;
        std::cin >> x >> y >> w;

        arr[i] = {x, y, -w};
    }

    std::cout << HighScore(arr, n) << '\n';
}