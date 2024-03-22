/**
 * @brief Find number of distinct colors in the subtree of each tree node.
 * @link https://cses.fi/problemset/task/1139
 * @date 13.01.2024
 */
#include <iostream>
#include <vector>
#include <unordered_set>

class Graph {
    std::vector<int> colors;
    std::vector<std::unordered_set<int>> sets;
    std::vector<std::vector<int>> adj_list;
    std::vector<size_t> dist_colors;
public:
    explicit Graph(std::vector<int> const &col)
            : colors(col), sets(col.size()), adj_list(col.size()), dist_colors(col.size()) {}

    void AddEdges(std::vector<std::pair<int, int>> const &edges) {
        for (auto const &[from, to]: edges) {
            adj_list[from].push_back(to);
            adj_list[to].push_back(from);
        }
    }

    std::vector<size_t> GetNumberDistinctColors() {
        dfs(1);
        return {dist_colors.begin() + 1, dist_colors.end()};
    }

private:
    void dfs(int u, int p = 0) {
        sets[u].insert(colors[u]);
        for (int v: adj_list[u]) {
            if (v == p) continue;
            dfs(v, u);
            if (sets[u].size() < sets[v].size()) swap(sets[u], sets[v]);
            sets[u].merge(sets[v]);

        }
        dist_colors[u] = sets[u].size();
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> colors(n);
    for (int &color: colors) {
        std::cin >> color;
    }
    colors.insert(colors.begin(), 0);
    std::vector<std::pair<int, int>> edges(n - 1);
    for (auto &[from, to]: edges) {
        std::cin >> from >> to;
    }
    auto graph = Graph(colors);
    graph.AddEdges(edges);
    auto const answer = graph.GetNumberDistinctColors();
    for (auto const &elem: answer) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';
    return 0;

}
