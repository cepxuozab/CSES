#include <cstdint>
#include <iostream>
#include <vector>


constexpr int MOD = 1e9 + 7;

auto matrix_mult(std::vector<std::vector<int64_t>> const &A, std::vector<std::vector<int64_t>> const &B)
  -> std::vector<std::vector<int64_t>>
{
    size_t const a_rows = A.size(), a_cols = A[0].size();
    size_t const b_rows = B.size(), b_cols = B.size();

    std::vector<std::vector<int64_t>> C(a_rows, std::vector<int64_t>(b_rows, 0));
    for (size_t i = 0; i < a_rows; i++) {
        for (size_t j = 0; j < b_cols; j++) {
            for (size_t k = 0; k < a_cols; k++) {
                C[i][j] += A[i][k] * B[k][j];
                C[i][j] %= MOD;
            }
        }
    }
    return C;
}

auto matrix_expo(std::vector<std::vector<int64_t>> &x, int64_t y) -> std::vector<std::vector<int64_t>>
{
    std::vector<std::vector<int64_t>> res(x.size(), std::vector<int64_t>(x[0].size()));
    for (size_t i = 0; i < x.size(); i++) res[i][i] = 1;
    while (y > 0) {
        if (y & 1) { res = matrix_mult(res, x); }
        y = y >> 1;
        x = matrix_mult(x, x);
    }
    return res;
}


auto main() -> int
{
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::vector<int64_t>> adj(n, std::vector<int64_t>(n));
    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        x--;
        y--;
        adj[x][y]++;
    }
    adj = matrix_expo(adj, k);
    std::cout << adj[0][n - 1];
}
