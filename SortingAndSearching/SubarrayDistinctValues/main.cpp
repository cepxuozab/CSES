#include <cassert>
#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> ReadFromOne(int n, std::istream &input = std::cin);

int64_t SubarrayDistinctValues(std::vector<int> const &nums, int k);

void Test();

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    Test();
    int n, k;
    std::cin >> n >> k;
    auto const arr = ReadFromOne(n);
    printf("%ld\n", SubarrayDistinctValues(arr, k));
}

std::vector<int> ReadFromOne(int const n, std::istream &input) {
    std::vector<int> arr(n + 1);
    for (int i = 1; i <= n; ++i) {
        input >> arr[i];
    }
    return arr;
}

int64_t SubarrayDistinctValues(std::vector<int> const &nums, int const k) {
    int const n = static_cast<int>(nums.size()) - 1;
    std::unordered_map<int, int> frequencies;
    int64_t ans{};
    int unique{};
    int right = 0;
    for (int left = 1; left <= n; ++left) {
        while (right < n && (frequencies[nums[right + 1]] >= 1 || unique < k)) {
            right++;
            frequencies[nums[right]]++;
            if (frequencies[nums[right]] == 1)
                unique++;
        }
        ans += (right - left + 1);

        frequencies[nums[left]]--;
        if (!frequencies[nums[left]])
            unique--;
    }
    return ans;
}

void Test() {
    std::vector<int> const arr{0, 1, 2, 3, 1, 1};
    assert(SubarrayDistinctValues(arr, 2) == 10);
}
