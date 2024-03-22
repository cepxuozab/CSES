#include <cstdint>
#include <iostream>
#include <vector>


constexpr int MOD = 1e9 + 7;

auto matrix_mult(std::vector<std::vector<int64_t>> const &A, std::vector<std::vector<int64_t>> const &B, int64_t mod)
  -> std::vector<std::vector<int64_t>>
{
    size_t const a_rows = A.size(), a_cols = A[0].size();
    size_t const b_rows = B.size(), b_cols = B.size();

    std::vector<std::vector<int64_t>> C(a_rows, std::vector<int64_t>(b_rows, 0));
    for (size_t i = 0; i < a_rows; i++) {
        for (size_t j = 0; j < b_cols; j++) {
            for (size_t k = 0; k < a_cols; k++) {
                C[i][j] += A[i][k] * B[k][j];
                C[i][j] %= mod;
            }
        }
    }
    return C;
}

auto matrix_expo(std::vector<std::vector<int64_t>> &A, int64_t b, int64_t m) -> std::vector<std::vector<int64_t>>
{
    std::vector<std::vector<int64_t>> res(A.size(), std::vector<int64_t>(A[0].size(), 1));
    while (b > 0) {
        if (b & 1) { res = matrix_mult(res, A, m); }
        A = matrix_mult(A, A, m);
        b >>= 1;
    }
    return res;
}


auto main() -> int
{
    int64_t n;
    std::cin >> n;
    std::vector<std::vector<int64_t>> f = { { 0, 1, 0, 0, 0, 0 },
        { 0, 0, 1, 0, 0, 0 },
        { 0, 0, 0, 1, 0, 0 },
        { 0, 0, 0, 0, 1, 0 },
        { 0, 0, 0, 0, 0, 1 },
        { 1, 1, 1, 1, 1, 1 } };
    auto const fn = matrix_expo(f, n, MOD);
    std::cout << fn[0][0];
}
