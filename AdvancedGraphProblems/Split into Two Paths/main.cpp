#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

void solve() {
    int node_count, edge_count;
    std::cin >> node_count >> edge_count;

    std::vector<std::vector<int>> adjacency_list(node_count);
    for (int i = 0; i < edge_count; ++i) {
        int from, to;
        std::cin >> from >> to;
        --from;
        --to;
        adjacency_list[from].push_back(to);
    }

    std::vector<bool> visited(node_count, false);
    std::vector<int> memo_dp(node_count, -1);
    std::vector<int> next_node(node_count, -1);

    auto dp_function = [&](auto&& self, int current) -> int {
        if (memo_dp[current] != -1) {
            return memo_dp[current];
        }
        int best_length = 1;
        next_node[current] = -1;
        for (int neighbor : adjacency_list[current]) {
            if (!visited[neighbor]) {
                int candidate_length = self(self, neighbor) + 1;
                if (candidate_length > best_length) {
                    best_length = candidate_length;
                    next_node[current] = neighbor;
                }
            }
        }
        return (memo_dp[current] = best_length);
    };

    std::fill(memo_dp.begin(), memo_dp.end(), -1);
    std::pair<int, int> longest_path = {0, -1};

    for (int node = 0; node < node_count; ++node) {
        if (!visited[node]) {
            int path_length = dp_function(dp_function, node);
            if (path_length > longest_path.first) {
                longest_path = {path_length, node};
            }
        }
    }

    if (longest_path.first * 2 < node_count) {
        std::cout << "NO\n";
        return;
    }

    // Mark nodes on the longest path as visited
    int current = longest_path.second;
    for (int i = 0; i < longest_path.first; ++i) {
        visited[current] = true;
        current = next_node[current];
    }

    int remaining_paths = node_count - longest_path.first + 1;

    std::vector<int> previous_node(node_count, -1);
    for (int node = 0; node < node_count; ++node) {
        if (!visited[node]) {
            next_node[node] = -1;
        } else if (next_node[node] != -1) {
            assert(previous_node[next_node[node]] == -1);
            previous_node[next_node[node]] = node;
        }
    }

    auto dfs_attach = [&](auto&& self, int start) -> bool {
        visited[start] = true;
        for (int neighbor : adjacency_list[start]) {
            if (previous_node[neighbor] == -1) {
                next_node[start] = neighbor;
                previous_node[neighbor] = start;
                return true;
            } else if (!visited[previous_node[neighbor]] && self(self, previous_node[neighbor])) {
                next_node[start] = neighbor;
                previous_node[neighbor] = start;
                return true;
            }
        }
        return false;
    };

    bool attachment_complete = false;
    while (!attachment_complete) {
        attachment_complete = true;
        std::fill(visited.begin(), visited.end(), false);
        for (int node = 0; node < node_count; ++node) {
            if (next_node[node] == -1 && dfs_attach(dfs_attach, node)) {
                --remaining_paths;
                attachment_complete = false;
            }
        }
    }

    if (remaining_paths > 2) {
        std::cout << "NO\n";
        return;
    }

    std::cout << "YES\n";
    for (int node = 0; node < node_count; ++node) {
        if (previous_node[node] == -1) {
            std::vector<int> path;
            int cur = node;
            while (cur != -1) {
                path.push_back(cur);
                cur = next_node[cur];
            }
            std::cout << path.size() << " ";
            for (int v : path) {
                std::cout << v + 1 << " ";
            }
            std::cout << "\n";
        }
    }

    if (remaining_paths == 1) {
        std::cout << "0\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}