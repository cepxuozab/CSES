/**
 * @file main.cpp
 * @author cepxuo (cepxuozab@gmail.com)
 * @brief Sum of Two Values
 * @link https://cses.fi/problemset/task/1640/
 * @version 0.1
 * @date 2024-01-13
 *
 * @copyright Copyright (c) 2024 *
 */

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <ranges>
#include <span>
#include <variant>
#include <vector>

/**
 * @brief Struct contains element end it index
 * may be sorted
 */
struct Data {
    int value{};
    int index{};
    auto operator<=>(Data const &other) const = default;
};

/**
 * @brief Read and sort Data array
 *
 * @param n quantity elements in array
 * @return std::vector<Data> array Data - indexing from 1
 */
std::vector<Data> ReadData(int n) {
    std::vector<Data> arr(n + 1);
    for (int i = 1; i <= n; ++i) {
        int a;
        std::cin >> a;
        arr[i] = {a, i};
    }
    std::ranges::sort(arr);
    return arr;
}

/**
 * @brief fing target in sorted array
 *
 * @param arr sorted array Data
 * @param target value to find
 * @return int index target in array or 0 when not find
 */
int BinarySearch(std::span<Data> arr, int target) {
    int left = 1;
    int right = static_cast<int>(arr.size());
    while (left <= right) {
        int mid = left + (right - left) / 2;
        auto const &[val, idx] = arr[mid];
        if (val == target) {
            return idx;
        }
        val < target ? left = mid + 1 : right = mid - 1;
    }
    return 0;
}

/**
 * @brief Find if exist two element in array with target sum
 * @param data sorted array
 * @param target expected sum of two element in array
 * @return std::variant<std::pair<size_t,size_t>,const char*> pair indexes or
 * error message
 */
std::variant<std::pair<size_t, size_t>, const char *> Request(std::span<Data> data, int target) {
    for (size_t i = 1; i < data.size(); ++i) {
        auto const &[val, idx] = data[i];
        if (auto const index = BinarySearch(data, target - val); index != 0 && index != idx) {
            return std::pair{idx, index};
        }
    }
    return "IMPOSSIBLE";
}

/**
 * @brief utility operator << for output pair of indexes
 *
 */
namespace {
    std::ostream &operator<<(std::ostream &out, std::pair<size_t, size_t> const &indexes) {
        return out << indexes.first << ' ' << indexes.second;
    }
} // namespace

int main() {
    int n, target;
    std::cin >> n >> target;
    auto arr = ReadData(n);
    auto request = Request(arr, target);
    std::visit([](auto &&arg) { std::cout << arg; }, request);
}
