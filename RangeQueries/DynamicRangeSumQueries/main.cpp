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

class RangeSum {
  unsigned n;
  std::vector<int> in;
  std::vector<int64_t> tree;

 public:
  RangeSum(std::vector<int> const& nums);
  void update(unsigned pos, int64_t val);
  auto sumRange(unsigned l, unsigned r) -> int64_t;

 private:
  void build();
};

int main() {
#ifdef _DEBUG
  if (freopen("input.txt", "r", stdin) == nullptr) {
    puts("can't open input.txt");
    return 0;
  }
#endif  // _DEBUG

  unsigned n;
  unsigned query;
  std::cin >> n >> query;
  std::vector<int> nums(n);
  std::cin >> nums;
  auto range = std::make_unique<RangeSum>(nums);
  std::vector<int64_t> answer;
  answer.reserve(query);
  while (query-- != 0) {
    int command;
    std::cin >> command;
    int left;
    int right;
    switch (command) {
      case 1:
        std::cin >> left >> right;
        range->update(left - 1, right);
        break;
      case 2:
        std::cin >> left >> right;
        answer.push_back(range->sumRange(left - 1, right - 1));
        break;
      default:
        break;
    }
  }
  print_vector(answer, '\n');
  return 0;
}

RangeSum::RangeSum(std::vector<int> const& nums) : n(nums.size()), in(nums) {
  tree.resize(2 * nums.size());
  build();
}

void RangeSum::update(unsigned pos, int64_t val) {
  pos += n;
  tree[pos] = val;
  while (pos > 0) {
    int left = pos;
    int right = pos;
    if (pos % 2 == 0) {
      right = pos + 1;
    } else {
      left = pos - 1;
    }
    tree[pos / 2] = tree[left] + tree[right];
    pos /= 2;
  }
}
auto RangeSum::sumRange(unsigned l, unsigned r) -> int64_t {
  l += n;
  r += n;
  int64_t sum = 0;
  while (l <= r) {
    if ((l % 2) == 1) {
      sum += tree[l];
      l++;
    }
    if ((r % 2) == 0) {
      sum += tree[r];
      r--;
    }
    l /= 2;
    r /= 2;
  }
  return sum;
}

void RangeSum::build() {
  for (unsigned i = n, j = 0; i < 2 * n; i++, j++) {
    tree[i] = in[j];
  }
  for (unsigned i = n - 1; i != 0; --i) {
    tree[i] = tree[i * 2] + tree[i * 2 + 1];
  }
}
