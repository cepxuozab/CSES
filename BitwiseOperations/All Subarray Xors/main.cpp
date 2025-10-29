#include <iostream>
#include <vector>
#include <algorithm>


// Быстрое преобразование Уолша–Адамара (Fast Walsh–Hadamard Transform)
void FWT(std::vector<long long>& a, bool inverse) {
    const std::size_t n = a.size();
    for (std::size_t step = 1; step < n; step <<= 1) {
        for (std::size_t i = 0; i < n; i += (step << 1)) {
            for (std::size_t j = 0; j < step; ++j) {
                const long long x = a[i + j];
                const long long y = a[i + j + step];
                a[i + j] = x + y;
                a[i + j + step] = x - y;
            }
        }
    }
    if (inverse) {
        for (auto& v : a) v /= static_cast<long long>(n);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::size_t n;
    if (!(std::cin >> n)) return 0;

    std::vector<int> arr(n);
    for (auto& x : arr) std::cin >> x;

    // Префиксные XOR'ы
    std::vector<int> pref(n + 1, 0);
    for (std::size_t i = 0; i < n; ++i)
        pref[i + 1] = pref[i] ^ arr[i];

    // Находим максимальное значение среди префиксов
    const int maxv = std::ranges::max(pref);

    // Размер массива для FWT — ближайшая степень двойки, >= maxv + 1
    std::size_t k = 1;
    while (k <= static_cast<std::size_t>(maxv)) k <<= 1;

    // Подсчёт частот префиксных XOR'ов
    std::vector<long long> freq(k, 0);
    for (int v : pref) ++freq[v];

    // XOR-свёртка (in-place)
    FWT(freq, false);
    for (auto& v : freq) v *= v;
    FWT(freq, true);

    // Результат
    std::vector<int> result;
    if (freq[0] > static_cast<long long>(n + 1)) result.push_back(0);
    for (std::size_t i = 1; i < k; ++i)
        if (freq[i] > 0) result.push_back(static_cast<int>(i));

    // Вывод
    std::cout << result.size() << '\n';
    for (std::size_t i = 0; i < result.size(); ++i) {
        if (i) std::cout << ' ';
        std::cout << result[i];
    }
    std::cout << '\n';
}
