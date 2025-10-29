#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1'000'000'007;

// Быстрое возведение в степень по модулю
auto mod_pow(long long a, long long e) -> long long {
    long long r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

// Обратный элемент по модулю (MOD — простое)
auto mod_inv(long long a) -> long long {
    return mod_pow(a, MOD - 2);
}

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<long long>> a(n, vector<long long>(m + 1));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= m; ++j)
            cin >> a[i][j];

    int row = 0;
    vector<int> where(m, -1);

    for (int col = 0; col < m && row < n; ++col) {
        // Найдём строку с ненулевым элементом в текущем столбце
        int sel = row;
        for (int i = row; i < n; ++i)
            if (a[i][col] != 0) {
                sel = i;
                break;
            }
        if (a[sel][col] == 0) continue;

        swap(a[sel], a[row]);
        where[col] = row;

        long long inv = mod_inv(a[row][col]);
        for (int j = col; j <= m; ++j)
            a[row][j] = a[row][j] * inv % MOD;

        // Обнулим текущий столбец в остальных строках
        for (int i = 0; i < n; ++i) {
            if (i != row && a[i][col] != 0) {
                long long factor = a[i][col];
                for (int j = col; j <= m; ++j) {
                    a[i][j] = (a[i][j] - factor * a[row][j]) % MOD;
                    if (a[i][j] < 0) a[i][j] += MOD;
                }
            }
        }
        ++row;
    }

    // Проверим на противоречия
    for (int i = 0; i < n; ++i) {
        bool allZero = true;
        for (int j = 0; j < m; ++j)
            if (a[i][j] != 0) allZero = false;
        if (allZero && a[i][m] != 0) {
            cout << -1 << "\n";
            return 0;
        }
    }

    // Восстановим решение
    vector<long long> ans(m, 0);
    for (int i = 0; i < m; ++i)
        if (where[i] != -1)
            ans[i] = a[where[i]][m];

    for (int i = 0; i < m; ++i)
        cout << ans[i] << (i + 1 == m ? '\n' : ' ');
}