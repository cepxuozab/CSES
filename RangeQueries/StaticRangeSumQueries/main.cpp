#include <cstdint>
#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>
auto const FASTIO = []() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return nullptr;
}();

template <typename T>
std::istream& operator>>(std::istream& input, std::vector<T>& arr) {
  for (auto& elem : arr) {
    input >> elem;
  }
  return input;
}

int main() {
#ifdef _DEBUG
  if (freopen("input.txt", "r", stdin) == nullptr) {
    puts("can't open input.txt");
    return 0;
  }
#endif  // _DEBUG

  int n, q;
  std::cin >> n >> q;
  std::vector<int64_t> nums(n);
  std::cin >> nums;
  std::partial_sum(nums.begin(), nums.end(), nums.begin());
  for (int i = 0; i < q; ++i) {
    size_t left, right;
    std::cin >> left >> right;
    right--;
    left--;
    auto res = nums[right] - (left == 0 ? 0 : nums[left - 1]);
    std::cout << res << '\n';
  }
  return 0;
}
