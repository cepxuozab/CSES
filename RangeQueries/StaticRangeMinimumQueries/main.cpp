#include <cstdint>
#include <iostream>
#include <memory>
#include <numeric>
#include <vector>
[[maybe_unused]] auto const FASTIO = []() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return nullptr;
}();

template <typename T>
std::istream& operator>>(std::istream& input, std::vector<T>& arr) {
  for (auto& a : arr) {
    input >> a;
  }
  return input;
}

template <typename T>
void print_vector(std::vector<T> const& arr, char ch = ' ') {
  for (auto&& a : arr) {
    std::cout << a << ch;
  }
}

class RMQ {
  std::vector<std::vector<int>> ranges;

 public:
  RMQ(std::vector<int> const& arr);

  [[nodiscard]] auto get_min(int left, int right) const -> int;
};

int main() {
#ifdef _DEBUG
  if (freopen("input.txt", "r", stdin) == nullptr) {
    puts("can't open input.txt");
    return 0;
  }
#endif  // _DEBUG

  int n;
  int query;
  std::cin >> n >> query;
  std::vector<int> nums(n);
  std::cin >> nums;
  auto const range = std::make_unique<RMQ>(nums);
  std::vector<int> answer;
  answer.reserve(query);

  while (query-- != 0) {
    int left;
    int right;
    std::cin >> left >> right;
    answer.push_back(range->get_min(left, right));
  }
  print_vector(answer, '\n');
  return 0;
}

RMQ::RMQ(std::vector<int> const& arr) {
  size_t const size = arr.size();
  ranges.emplace_back(arr);
  for (size_t i = 1, k = 2; k <= size; ++i, k *= 2) {
    ranges.emplace_back();
    ranges.back().resize(size - k + 1);
    for (size_t j = 0; j + k <= size; ++j) {
      ranges[i][j] = std::min(ranges[i - 1][j], ranges[i - 1][j + k / 2]);
    }
  }
}

auto RMQ::get_min(int left, int right) const -> int {
  auto diff = right - left + 1;
  int i = 0;
  int k = 1;
  for (; k * 2 <= diff; i++, k *= 2)
    ;
  return std::min(ranges[i][left - 1], ranges[i][right - k]);
}
