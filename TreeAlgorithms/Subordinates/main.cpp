/**
 * @brief Find number of  subordinates for each employee.
 * @link https://cses.fi/problemset/task/1674/
 * @date 13.01.2024
 */
#include <iostream>
#include <vector>
#include <span>
std::vector<int> CountSubordinates(std::span<int> employees) {
    std::vector<std::vector<int>> adj_list(employees.size() + 1);
    int v = 1;
    for (int employee: employees) {
        adj_list[employee - 1].push_back(v++);
    }
    std::vector<int> size(adj_list.size());
    auto dfs = [&](auto &&dfs, int p) -> void {
        for (int v: adj_list[p]) {
            dfs(dfs, v);
            size[p] += size[v] + 1;
        }
    };
    dfs(dfs, 0);
    return size;
}

void Test();

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    Test();
    int n;
    std::cin >> n;
    std::vector<int> employees(n - 1);
    for (auto &employee: employees) {
        std::cin >> employee;
    }
    auto const subordinates = CountSubordinates(employees);
    for (int sub: subordinates) {
        std::cout << sub << ' ';
    }
    return 0;
}

#include <cassert>

void Test() {
    std::vector test{1,1,2,3};
    assert(CountSubordinates(test) == (std::vector<int>{4, 1, 1, 0, 0}));
}



