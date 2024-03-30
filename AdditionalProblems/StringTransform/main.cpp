#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

auto main() -> int {
    std::string str;
    std::cin >> str;
    std::vector<int> arr(str.size());
    std::iota(arr.begin(), arr.end(), 0);
    auto compare = [&str](int i, int j) { return str[i] < str[j]; };
    std::ranges::stable_sort(arr, compare);
    int ptr = arr.front();
    while (ptr != 0) {
        ptr = arr[ptr];
        std::cout << str[ptr];
    }
}