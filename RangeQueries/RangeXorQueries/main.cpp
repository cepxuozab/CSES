#include <iostream>
#include <memory>
#include <vector>
[[maybe_unused]] static const auto FastIo = []() {
    std::ios_base::sync_with_stdio(false);
    auto constexpr ptr = nullptr;
    std::cin.tie(ptr);
    return nullptr;
}();
template<typename T>
auto operator>>(std::istream &input, std::vector<T> &arr) -> std::istream & {
    for (auto &a: arr) {
        input >> a;
    }
    return input;
}
template<typename T>
void print_vector(std::vector<T> const &arr, char ch = ' ') {
    for (auto &&a: arr) {
        std::cout << a << ch;
    }
}
class RangeXOR {
    int n;
    std::vector<int> in;
    std::vector<int64_t> tree;

public:
    explicit RangeXOR(std::vector<int> const &nums) : n(static_cast<int>(nums.size())), in(nums) {
        tree.resize(2 * nums.size());
        build();
    }

    [[nodiscard]] auto xorRange(int l, int r) const -> int64_t {
        l += n;
        r += n;
        int64_t sum = 0;
        while (l <= r) {
            if ((l % 2) == 1) {
                sum = sum ^ tree[l];
                l++;
            }
            if ((r % 2) == 0) {
                sum = sum ^ tree[r];
                r--;
            }
            l /= 2;
            r /= 2;
        }
        return sum;
    }

private:
    void build() {
        for (int i = n, j = 0; i < 2 * n; i++, j++) {
            tree[i] = in[j];
        }
        for (int i = n - 1; i > 0; --i) {
            tree[i] = tree[i * 2] ^ tree[i * 2 + 1];
        }
    }
};
auto main() -> int {
    int n;
    int query;
    std::cin >> n >> query;
    std::vector<int> nums(n);
    std::cin >> nums;
    auto const range = std::make_unique<RangeXOR>(nums);
    std::vector<int64_t> answer;
    answer.reserve(query);
    while (query-- != 0) {
        int left;
        int right;
        std::cin >> left >> right;
        answer.push_back(range->xorRange(left - 1, right - 1));
    }
    print_vector(answer, '\n');
    return 0;
}
