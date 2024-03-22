#include <cstdint>
#include <iostream>
#include <vector>


constexpr int64_t inf = 1LL << 60;

auto matrix_mult(std::vector<std::vector<int64_t>> const &A, std::vector<std::vector<int64_t>> const &B)
  -> std::vector<std::vector<int64_t>>
{
    size_t const a_rows = A.size();
    std::vector<std::vector<int64_t>> C(A.size(), std::vector<int64_t>(B[0].size()));
    for (size_t i = 0; i < a_rows; i++)
        for (size_t j = 0; j < a_rows; j++) C[i][j] = inf;
    for (size_t i = 0; i < A.size(); i++)
        for (size_t j = 0; j < B[0].size(); j++)
            for (size_t k = 0; k < A[0].size(); k++) C[i][j] = std::min(C[i][j], A[i][k] + B[k][j]);
    return C;
}

auto matrix_expo(std::vector<std::vector<int64_t>> &x, int64_t y) -> std::vector<std::vector<int64_t>>
{
    std::vector<std::vector<int64_t>> res(x.size(), std::vector<int64_t>(x[0].size()));
    int f = 0;
    while (y > 0) {
        if (y & 1) {
            if (f)
                res = matrix_mult(res, x);
            else
                res = x, f = 1;
        }
        y = y >> 1;
        x = matrix_mult(x, x);
    }
    return res;
}


auto main() -> int
{
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::vector<int64_t>> adj(n, std::vector<int64_t>(n, inf));
    for (int i = 0; i < m; i++) {
        int x, y, c;
        std::cin >> x >> y >> c;
        x--;
        y--;
        adj[x][y] = std::min<int64_t>(adj[x][y], c);
    }
    adj = matrix_expo(adj, k);
    auto const res = adj.front().back();
    std::cout << (res < inf ? res : -1);
}
