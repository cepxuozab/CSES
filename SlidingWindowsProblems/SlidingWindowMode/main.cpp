#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <utility>

auto sliding_windows_mode(std::vector<int> const &arr, int windows_size) -> std::vector<int> {
    std::unordered_map<int, int> frequency_map;
    auto compare = [](std::pair<int, int> const &lhs, std::pair<int, int> const &rhs) {
        return lhs.first != rhs.first ? lhs.first > rhs.first : lhs.second < rhs.second;
    };
    std::set<std::pair<int, int>, decltype(compare)> bst(compare);
    for (int i = 0; i < windows_size; ++i)frequency_map[arr[i]]++;
    for (auto const &[key, value]: frequency_map)bst.emplace(value, key);
    std::vector<int> answer;
    answer.push_back(bst.begin()->second);
    for (int j = windows_size; std::cmp_less(j, arr.size()); j++) {
        auto &prev = frequency_map[arr[j - windows_size]];
        bst.erase({prev, arr[j - windows_size]});
        prev--;
        if (prev > 0)bst.emplace(prev, arr[j - windows_size]);
        auto &curr = frequency_map[arr[j]];
        bst.erase({curr, arr[j]});
        curr++;
        bst.emplace(curr, arr[j]);
        answer.push_back(bst.begin()->second);

    }
    return answer;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    std::vector<int> arr(n);
    for (auto &elem: arr)std::cin >> elem;
    for (int i: sliding_windows_mode(arr, k)) {
        std::cout << i << ' ';
    }
    return 0;
}