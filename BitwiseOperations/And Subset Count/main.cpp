#include <iostream>
#include <vector>

constexpr int MOD = 1'000'000'007;

// Быстрое возведение в степень по модулю
int mod_pow(int base, int exp) {
    long long result = 1;
    long long a = base % MOD;
    while (exp > 0) {
        if (exp & 1)
            result = result * a % MOD;
        a = a * a % MOD;
        exp >>= 1;
    }
    return static_cast<int>(result);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    int max_val = 0;
    for (int &x: a) {
        std::cin >> x;
        if (x > max_val) max_val = x;
    }

    // Находим минимальную степень двойки, покрывающую max_val (верхняя граница диапазона масок)
    int max_mask = 1;
    while (max_mask <= max_val)
        max_mask <<= 1;

    std::vector<int> cnt(max_mask, 0);
    for (int x: a)
        ++cnt[x];

    // Обратное Zeta-преобразование по подмножествам:
    // после этого cnt[mask] = количество элементов a[i], у которых (a[i] & mask) == mask
    for (int bit = 0; (1 << bit) < max_mask; ++bit) {
        for (int mask = 0; mask < max_mask; ++mask) {
            if ((mask & (1 << bit)) == 0) {
                cnt[mask] += cnt[mask | (1 << bit)];
            }
        }
    }

    // dp[mask] = количество непустых подмножеств элементов a[],
    //            у которых побитовое AND всех элементов равно mask
    std::vector<int> dp(max_mask, 0);
    for (int mask = 0; mask < max_mask; ++mask) {
        if (cnt[mask] > 0) {
            dp[mask] = mod_pow(2, cnt[mask]) - 1;
            if (dp[mask] < 0) dp[mask] += MOD;
        }
    }

    // Преобразование Мёбиуса (по подмножествам):
    // вычитаем вклад всех надмножеств, чтобы оставить только точные AND = mask
    for (int bit = 0; (1 << bit) < max_mask; ++bit) {
        for (int mask = 0; mask < max_mask; ++mask) {
            if ((mask & (1 << bit)) == 0) {
                dp[mask] = (dp[mask] - dp[mask | (1 << bit)] + MOD) % MOD;
            }
        }
    }

    // Выводим dp[0..n] (скорее всего, для отладки; обычно выводят dp[0])
    for (int k = 0; k <= n; ++k) {
        std::cout << dp[k];
        if (k < n) std::cout << ' ';
    }
    std::cout << '\n';

    return 0;
}
