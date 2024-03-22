#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>
[[maybe_unused]] static const auto _ = []() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return nullptr;
}();
template <typename T>
auto operator>>(std::istream& input, std::vector<T>& arr) -> std::istream& {
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

class NumArray {
  std::vector<int> nums_;

  struct Node;
  using NodeHolder = std::unique_ptr<Node>;

  struct Node {
    int start = 0;
    int end = 0;
    int64_t sum = 0;
    NodeHolder left = nullptr, right = nullptr;
    Node(int a, int b) : start(a), end(b) {}
  };

  auto buildTree(int start, int end) -> NodeHolder {
    if (start > end) {
      return nullptr;
    }

    auto node = std::make_unique<Node>(start, end);

    if (start == end) {
      node->sum = nums_[start];
      return node;
    }

    int mid = start + (end - start) / 2;

    node->left = buildTree(start, mid);

    node->right = buildTree(mid + 1, end);

    node->sum = node->left->sum + node->right->sum;

    return node;
  }
  auto modifyTree(int i, int64_t val, NodeHolder& node) -> int64_t {
    if (!node) {
      return 0;
    }

    int64_t diff;

    if (node->start == i && node->end == i) {
      diff = val - node->sum;
      node->sum = val;
      return diff;
    }

    int mid = (node->start + node->end) / 2;

    if (i > mid) {
      diff = modifyTree(i, val, node->right);
    } else {
      diff = modifyTree(i, val, node->left);
    }

    node->sum += diff;

    return diff;
  }

  auto queryTree(int i, int j, NodeHolder const& node) -> int64_t {
    if (!node) {
      return 0;
    }
    if (node->start == i && node->end == j) {
      return node->sum;
    }

    int mid = (node->start + node->end) / 2;

    if (i > mid) {
      return queryTree(i, j, node->right);
    }
    if (j <= mid) {
      return queryTree(i, j, node->left);
    }

    return queryTree(i, mid, node->left) + queryTree(mid + 1, j, node->right);
  }

  NodeHolder root = nullptr;

 public:
  NumArray(std::vector<int>& nums)
      : nums_(nums), root(buildTree(0, nums.size() - 1)) {}

  void update(int i, int64_t val) { modifyTree(i, val, root); }

  auto sumRange(int i, int j) -> int64_t { return queryTree(i, j, root); }
};

auto main() -> int {
  int n;
  int query;
  std::cin >> n >> query;
  std::vector<int> nums(n);
  std::cin >> nums;
  auto range = std::make_unique<NumArray>(nums);
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
