#include <iostream>
#include <vector>
#include <array>
#include <string>

struct TwoSat {
    int n;
    std::vector<std::vector<int>> graph;
    std::vector<int> assignment;

    explicit TwoSat(int _n = 0) : n(_n), graph(2 * _n), assignment(_n, -1) {}

    void add_clause(int x, int y) {
        // Преобразуем литералы в индексы: положительный x → 2*x, отрицание → 2*x+1
        int a = (x >= 0) ? (2 * x) : (-2 * x - 1);
        int b = (y >= 0) ? (2 * y) : (-2 * y - 1);
        graph[a].push_back(b ^ 1);
        graph[b].push_back(a ^ 1);
    }

    std::vector<int> index, component;
    std::vector<int> stack;
    int time_counter = 0;

    int dfs(int v) {
        int lowlink = index[v] = ++time_counter;
        stack.push_back(v);

        for (int to: graph[v]) {
            if (component[to] == 0) {
                if (index[to] == 0) {
                    lowlink = std::min(lowlink, dfs(to));
                } else {
                    lowlink = std::min(lowlink, index[to]);
                }
            }
        }

        if (lowlink == index[v]) {
            int u;
            do {
                u = stack.back();
                stack.pop_back();
                component[u] = lowlink;
                int var = u >> 1;
                if (assignment[var] == -1) {
                    assignment[var] = u & 1;
                }
            } while (u != v);
        }

        return index[v] = lowlink;
    }

    bool solve() {
        assignment.assign(n, -1);
        index.assign(2 * n, 0);
        component.assign(2 * n, 0);
        time_counter = 0;
        stack.clear();

        for (int i = 0; i < 2 * n; ++i) {
            if (index[i] == 0) {
                dfs(i);
            }
        }

        for (int i = 0; i < n; ++i) {
            if (component[2 * i] == component[2 * i + 1]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> grid(n);
    for (auto &row: grid) {
        std::cin >> row;
    }

    TwoSat solver(n * m);

    constexpr std::array<int, 4> dx = {0, 0, 1, -1};
    constexpr std::array<int, 4> dy = {1, -1, 0, 0};

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int dir = 0; dir < 4; ++dir) {
                int ni = i + dx[dir];
                int nj = j + dy[dir];
                if (ni < 0 || ni >= n || nj < 0 || nj >= m) {
                    continue;
                }

                for (int a: {1, 2}) {
                    for (int b: {1, 2}) {
                        char current = grid[i][j];
                        char neighbor = grid[ni][nj];
                        if ((current + a - 'A') % 3 == (neighbor + b - 'A') % 3) {
                            int var1 = i * m + j;
                            int var2 = ni * m + nj;

                            int lit1 = (a == 1) ? var1 : ~var1;
                            int lit2 = (b == 1) ? var2 : ~var2;

                            solver.add_clause(lit1, lit2);
                        }
                    }
                }
            }
        }
    }

    if (!solver.solve()) {
        std::cout << "IMPOSSIBLE\n";
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char base = grid[i][j];
            int var_index = i * m + j;
            int add = solver.assignment[var_index] + 1; // 0 → +1, 1 → +2
            char result = 'A' + (base + add - 'A') % 3;
            std::cout << result;
        }
        std::cout << '\n';
    }

    return 0;
}