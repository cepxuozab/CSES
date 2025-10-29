#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;

struct Matrix {
    long long a, b, c, d;

    Matrix(long long a = 1, long long b = 0, long long c = 0, long long d = 1)
            : a(a % MOD), b(b % MOD), c(c % MOD), d(d % MOD) {}
};

auto multiply(const Matrix &x, const Matrix &y) -> Matrix {
    return {
            (x.a * y.a + x.b * y.c) % MOD,
            (x.a * y.b + x.b * y.d) % MOD,
            (x.c * y.a + x.d * y.c) % MOD,
            (x.c * y.b + x.d * y.d) % MOD
    };
}

auto power(Matrix base, long long exp) -> Matrix {
    Matrix res; // identity matrix
    while (exp > 0) {
        if (exp & 1) res = multiply(res, base);
        base = multiply(base, base);
        exp >>= 1;
    }
    return res;
}

auto count_sequences(long long n, int e) -> long long {
    if (e == 0) {
        return 1;
    }
    if (n == 1) {
        return (e + 1) % MOD;
    }
    // Transition matrix M = [[0, 1],
    //                        [e, 1]]
    Matrix M(0, 1, e, 1);
    Matrix M_exp = power(M, n - 1);

    // initial vector v1 = [e, 1]
    long long dp0 = ((long long) e * M_exp.a % MOD + M_exp.c) % MOD;
    long long dp1 = ((long long) e * M_exp.b % MOD + M_exp.d) % MOD;
    return (dp0 + dp1) % MOD;
}

auto factorize(long long k) -> vector<pair<long long, int>> {
    vector<pair<long long, int>> factors;
    if (k <= 1) return factors;
    long long temp = k;
    for (long long i = 2; i * i <= temp; i++) {
        if (temp % i == 0) {
            int cnt = 0;
            while (temp % i == 0) {
                cnt++;
                temp /= i;
            }
            factors.emplace_back(i, cnt);
        }
    }
    if (temp > 1) {
        factors.emplace_back(temp, 1);
    }
    return factors;
}

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n, k;
        cin >> n >> k;

        if (k == 1) {
            cout << 1 << '\n';
            continue;
        }

        auto factors = factorize(k);
        long long ans = 1;
        for (auto [prime, exp]: factors) {
            long long ways = count_sequences(n, exp);
            ans = (ans * ways) % MOD;
        }
        cout << ans << '\n';
    }

    return 0;
}