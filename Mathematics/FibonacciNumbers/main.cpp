#include <cstdint>
#include <iostream>

constexpr int MOD = 1e9 + 7;

void mult(int64_t A[2][2], int64_t B[2][2])
{
    int64_t C[2][2]{};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                C[i][j] += A[i][k] * B[k][j];
                C[i][j] %= MOD;
            }
        }
    }
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) A[i][j] = C[i][j];
}


auto main() -> int
{
    int64_t n, x[2][2]{}, y[2][2]{};
    x[0][1] = x[1][0] = x[1][1] = y[0][0] = y[1][1] = 1;
    std::cin >> n;
    while (n) {
        if (n & 1) mult(y, x);
        mult(x, x);
        n >>= 1;
    }
    std::cout << y[0][1];
}
