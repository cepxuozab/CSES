#include <iostream>
#include <vector>
#include <unordered_map>
#include <span>

class SlidingWindowDistinct {
private:
    std::unordered_map<int, int> freq_;
    int distinct_count_ = 0;

public:
    void add(int value) {
        auto &count = freq_[value];
        if (count == 0) {
            ++distinct_count_;
        }
        ++count;
    }

    void remove(int value) {
        auto &count = freq_[value];
        if (count == 1) {
            --distinct_count_;
        }
        --count;
    }

    [[nodiscard]] int getDistinctCount() const noexcept {
        return distinct_count_;
    }
};

std::vector<int> findDistinctInWindows(std::span<const int> values, int window_size) {
    std::size_t w_size = static_cast<std::size_t>(window_size);
    if (values.empty() || window_size <= 0 || w_size > values.size()) {
        return {};
    }

    std::vector<int> result;
    result.reserve(values.size() - w_size + 1);

    SlidingWindowDistinct window;

    for (size_t i = 0; i < w_size; ++i) {
        window.add(values[i]);
    }
    result.push_back(window.getDistinctCount());

    for (std::size_t i = w_size; i < values.size(); ++i) {
        window.remove(values[i - w_size]);
        window.add(values[i]);
        result.push_back(window.getDistinctCount());
    }

    return result;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::vector<int> values(n);
    for (auto &value: values)std::cin >> value;

    const auto result = findDistinctInWindows(values, k);

    for (std::size_t i = 0; i < result.size(); ++i) {
        std::cout << result[i] << ' ';
    }

}