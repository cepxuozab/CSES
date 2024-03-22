#include <iostream>
#include <memory>
#include <utility> //for exchange
#include <vector>

[[maybe_unused]] static const auto FastIo = []() {
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
        tree.resize(nums.size() + 1);
        build();
    }
    [[nodiscard]] auto getNum(int pos) const -> int64_t {
        int64_t sum = 0;
        while (pos != 0) {
            sum += tree[pos];
            pos -= pos & -pos;
        }
        return sum;
    }
    void add(int left, int right, int64_t x) {
        add(left, x);
        add(right + 1, -x);
    }

private:
    void add(int pos, int64_t x) {
        while (pos <= static_cast<int>(n)) {
            tree[pos] += x;
            pos += pos & -pos;
        }
    }

    void build() {
        int64_t y = 0;
        for (size_t i = 1; i <= n; ++i) {
            add(i, in[i - 1] - std::exchange(y, in[i - 1]));
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
        int val;
        int pos;
        switch (command) {
            case 1:
                std::cin >> left >> right >> val;
                range->add(left, right, val);
                break;
            case 2:
                std::cin >> pos;
                answer.push_back(range->getNum(pos));
                break;
            default:
                break;
        }
    }
    print_vector(answer, '\n');
    return 0;
}
