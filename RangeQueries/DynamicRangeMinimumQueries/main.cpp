#include <algorithm>
#include <iostream>
#include <limits>
#include <memory>
#include <vector>

[[maybe_unused]] static const auto FASTIO = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
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
class RangeMin {
    size_t n;
    std::vector<int> in;
    std::vector<int64_t> tree;

public:
    explicit RangeMin(std::vector<int> const &nums) : n(nums.size()), in(nums) {
        tree.resize(2 * nums.size());
        build();
    }
    void update(size_t pos, int64_t val) {
        pos += n;
        tree[pos] = val;
        while (pos > 0) {
            auto left = pos;
            auto right = pos;
            if (pos % 2 == 0) {
                right = pos + 1;
            } else {
                left = pos - 1;
            }
            tree[pos / 2] = std::min(tree[left], tree[right]);
            pos /= 2;
        }
    }
    [[nodiscard]] auto minRange(size_t l, size_t r) const -> int64_t {
        l += n;
        r += n;
        int64_t sum = std::numeric_limits<int>::max();
        while (l <= r) {
            if ((l % 2) == 1) {
                sum = std::min(sum, tree[l]);
                l++;
            }
            if ((r % 2) == 0) {
                sum = std::min(sum, tree[r]);
                r--;
            }
            l /= 2;
            r /= 2;
        }
        return sum;
    }

private:
    void build() {
        for (size_t i = n, j = 0; i < 2 * n; i++, j++) {
            tree[i] = in[j];
        }
        for (size_t i = n - 1; i > 0; --i) {
            tree[i] = std::min(tree[i * 2], tree[i * 2 + 1]);
        }
    }
};
auto main() -> int {
    int n;
    int query;
    std::cin >> n >> query;
    std::vector<int> nums(n);
    std::cin >> nums;
    auto range = std::make_unique<RangeMin>(nums);
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
                answer.push_back(range->minRange(left - 1, right - 1));
                break;
            default:
                break;
        }
    }
    print_vector(answer, '\n');
    return 0;
}
