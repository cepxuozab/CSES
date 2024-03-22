#include <iostream>
#include <string>
#include <vector>
#include <queue>

struct Position {
    int i{};
    int j{};

    auto operator<=>(Position const &) const = default;
};

auto ReadLabyrinth(std::vector<std::string> &labyrinth) -> std::pair<Position, Position>;

class Graph {
    std::vector<std::string> grid;

public:
    explicit Graph(std::vector<std::string> labyrinth);

    auto GetPath(Position start, Position end) -> std::string {
        std::vector<std::vector<int>> visited(grid.size());
        for (auto &vis: visited) {
            vis.resize(grid.front().size(), -1);
        }
        if (!FindPath(visited, start, end)) {
            return "NO\n";
        }
        int k = visited[end.i][end.j];
        std::string answer{"YES\n"};
        answer.append(std::to_string(k) + "\n");
        std::string p;
        auto [i, j] = end;
        int n = static_cast<int>(grid.size());
        while (i != start.i || j != start.j) {
            if (i > 0 && visited[i - 1][j] == k - 1) {
                p.push_back('D');
                i--;
            } else if (i < n - 1 && visited[i + 1][j] == k - 1) {
                p.push_back('U');
                i++;
            } else if (j > 0 && visited[i][j - 1] == k - 1) {
                p.push_back('R');
                j--;
            } else {
                p.push_back('L');
                j++;
            }
            k--;
        }
        answer.append({p.rbegin(), p.rend()});
        return answer;
    }

private:
    auto FindPath(std::vector<std::vector<int>> &visited, Position start, Position end) -> bool;

};

auto main() -> int {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> labyrinth(n);
    auto [start, end] = ReadLabyrinth(labyrinth);
    auto graph = Graph(labyrinth);
    std::cout << graph.GetPath(start, end);
}

auto ReadLabyrinth(std::vector<std::string> &labyrinth) -> std::pair<Position, Position> {
    Position src, dst;
    int n = static_cast<int>(labyrinth.size());
    for (int i = 0; i < n; ++i) {
        auto &line = labyrinth[i];
        std::cin >> line;
        if (auto pos = line.find('A');pos != std::string::npos) {
            src = {i, static_cast<int>(pos)};
        }
        if (auto pos = line.find('B');pos != std::string::npos) {
            dst = {i, static_cast<int>(pos)};
        }
    }
    return {src, dst};
}

Graph::Graph(std::vector<std::string> labyrinth) : grid(std::move(labyrinth)) {}

auto Graph::FindPath(std::vector<std::vector<int>> &visited, Position start, Position end) -> bool {
    int n = static_cast<int>(grid.size());
    int m = static_cast<int>(grid.front().size());
    int dir_x[] = {-1, 1, 0, 0};
    int dir_y[] = {0, 0, 1, -1};
    auto check = [this, n, m, &visited](int i, int j) -> bool {
        return i >= 0 && i < n && j >= 0 && j < m && grid[i][j] != '#' && visited[i][j] == -1;
    };
    struct Data {
        Position pos;
        int k;
    };
    std::queue<Data> queue;
    queue.push({start, 0});
    while (!queue.empty()) {
        auto [curr, k] = queue.front();
        queue.pop();
        auto [i, j] = curr;
        if (visited[i][j] != -1) {
            continue;
        }
        visited[i][j] = k;
        if (curr == end) {
            return true;
        }
        for (int idx = 0; idx < 4; ++idx) {
            auto dx = i + dir_x[idx];
            auto dy = j + dir_y[idx];
            if (check(dx, dy)) {
                queue.push({{dx, dy}, k + 1});
            }
        }

    }
    return false;
}