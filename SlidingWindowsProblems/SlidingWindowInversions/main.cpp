#include <iostream>
#include <vector>
#include <algorithm>
#include <span>



class FenwickTree {
public:
    explicit FenwickTree(int n) : tree(n + 1, 0) {}

    // Обновление значения в позиции idx на delta
    void update(int idx, int delta) {
        for (int i = idx; i < static_cast<int>(tree.size()); i += i & -i) {
            tree[i] += delta;
        }
    }

    // Префиксная сумма [1, idx]
    int query(int idx) const {
        int sum = 0;
        for (int i = idx; i > 0; i -= i & -i) {
            sum += tree[i];
        }
        return sum;
    }

private:
    std::vector<int> tree;
};

std::vector<int> compress_values(std::span< const int> values) {
    std::vector<int> sorted(values.begin(),values.end());
    std::ranges::sort(sorted);
    sorted.erase(std::ranges::unique(sorted).begin(), sorted.end());

    std::vector<int> result;
    result.reserve(values.size());

    for (int val: values) {
        auto pos = std::ranges::lower_bound(sorted, val) - sorted.begin();
        result.push_back(static_cast<int>(pos) + 1); // 1-based indexing
    }

    return result;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, K;
    std::cin >> N >> K;

    std::vector<int> a(N);
    for (int &x: a) {
        std::cin >> x;
    }

    a = compress_values(a);

    FenwickTree ft(N);
    long long inversions = 0;

    // Инициализация первого окна
    for (int i = 0; i < K; ++i) {
        inversions += i - ft.query(a[i]);
        ft.update(a[i], 1);
    }

    // Вывод первого результата
    std::cout << inversions<<' ';


    // Скользящее окно
    for (int i = K; i < N; ++i) {
        // Удаляем элемент, выходящий из окна
        inversions -= ft.query(a[i - K] - 1);
        ft.update(a[i - K], -1);

        // Добавляем новый элемент
        inversions += (K - 1) - ft.query(a[i]);
        ft.update(a[i], 1);

        std::cout << inversions<<' ';

    }

    return 0;
}