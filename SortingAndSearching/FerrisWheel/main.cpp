/**
* @brief Ferris Wheel
 * @link https://cses.fi/problemset/task/1090
 * @date 15.01.2023
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <span>
#include <cstdint>

auto ReadAndSortData(unsigned n) -> std::vector<int64_t>;

auto MinimumNumberOfGondolas(int64_t max_weight, std::span<int64_t> childrensWeight) -> int;

auto main() -> int {
    unsigned n;
    int64_t maxWeight = 0;
    std::cin >> n >> maxWeight;
    auto childrens = ReadAndSortData(n);
    std::cout << MinimumNumberOfGondolas(maxWeight, childrens);
    return 0;
}

auto ReadAndSortData(unsigned n) -> std::vector<int64_t> {
    std::vector<int64_t> arr;
    arr.resize(n);
    for (int64_t &data: arr) {
        std::cin >> data;
    }
    std::ranges::sort(arr);
    return arr;
}

auto MinimumNumberOfGondolas(int64_t max_weight, std::span<int64_t> childrensWeight) -> int {
    int const n = static_cast<int>(childrensWeight.size());
    int answer = 0;
    int i = 0;
    int j = n - 1;
    while (i <= j) {
        if (childrensWeight[j] + childrensWeight[i] > max_weight) {
            j--;
        } else {
            i++;
            j--;
        }
        answer++;
    }
    return answer;

}