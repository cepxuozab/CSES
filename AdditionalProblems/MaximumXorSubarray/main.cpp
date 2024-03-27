#include <array>
#include <cstdint>
#include <iostream>
#include <limits>
#include <memory>
#include <vector>

struct TrieNode {
    int value = 0;  // Only used in leaf nodes
    std::array<std::unique_ptr<TrieNode>, 2> arr{nullptr, nullptr};
};

constexpr int INT_SIZE = 32;
void insert(TrieNode* root, int pre_xor) {
    TrieNode* temp = root;
    for (int i = INT_SIZE - 1; i >= 0; i--) {
        size_t val = (pre_xor & (1 << i)) != 0 ? 1 : 0;
        if (temp->arr[val] == nullptr) {
            temp->arr[val] = std::make_unique<TrieNode>();
        }
        temp = temp->arr[val].get();
    }
    temp->value = pre_xor;
}

auto query(TrieNode* root, int pre_xor) -> int {
    TrieNode* temp = root;
    for (int i = INT_SIZE - 1; i >= 0; i--) {
        size_t val = (pre_xor & (1 << i)) != 0 ? 1 : 0;
        if (temp->arr[1 - val] != nullptr) {
            temp = temp->arr[1 - val].get();
        } else if (temp->arr[val] != nullptr) {
            temp = temp->arr[val].get();
        }
    }
    return pre_xor ^ (temp->value);
}
auto maxSubarrayXOR(std::vector<int> const& arr, int n) -> int {
    auto* root = new TrieNode();
    insert(root, 0);
    int result = std::numeric_limits<int>::min();
    int pre_xor = 0;
    for (int i = 0; i < n; i++) {
        pre_xor = pre_xor ^ arr[i];
        insert(root, pre_xor);
        result = std::max(result, query(root, pre_xor));
    }
    delete root;
    return result;
}

auto main() -> int {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int& i : arr) {
        std::cin >> i;
    }
    std::cout << maxSubarrayXOR(arr, n);
}