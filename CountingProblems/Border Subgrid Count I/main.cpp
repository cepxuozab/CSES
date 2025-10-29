#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <utility>
#include <numeric>

struct binary_indexed_tree {
    std::vector<int> values;

    binary_indexed_tree(size_t size) : values(size + 1, 0) {}

    void modify(size_t pos, int diff) {
        for (; pos < values.size(); pos += (pos & -static_cast<long long>(pos))) {
            values[pos] += diff;
        }
    }

    int query(size_t pos) {
        int accumulate = 0;
        for (; pos > 0; pos -= (pos & -static_cast<long long>(pos))) {
            accumulate += values[pos];
        }
        return accumulate;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::vector<long long> answer(k, 0LL);
    std::vector<std::string> grid(n);
    std::vector<std::vector<int>> extend_up_right(n, std::vector<int>(n, 1));
    std::vector<std::vector<int>> extend_down_left(n, std::vector<int>(n, 1));

    for (int i = 0; i < n; ++i) {
        std::cin >> grid[i];
    }

    // extend up
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == grid[i - 1][j]) {
                extend_up_right[i][j] = extend_up_right[i - 1][j] + 1;
            } else {
                extend_up_right[i][j] = 1;
            }
        }
    }

    // extend down
    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == grid[i + 1][j]) {
                extend_down_left[i][j] = extend_down_left[i + 1][j] + 1;
            } else {
                extend_down_left[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        // extend left
        extend_down_left[i][0] = 1;
        for (int j = 1, value = 1; j < n; ++j) {
            if (grid[i][j - 1] == grid[i][j]) {
                value++;
            } else {
                value = 1;
            }
            extend_down_left[i][j] = std::min(extend_down_left[i][j], value);
        }

        // extend right
        extend_up_right[i][n - 1] = 1;
        for (int j = n - 2, value = 1; j >= 0; --j) {
            if (grid[i][j + 1] == grid[i][j]) {
                value++;
            } else {
                value = 1;
            }
            extend_up_right[i][j] = std::min(extend_up_right[i][j], value);
        }
    }

    for (int diag = 0; diag <= 2 * n - 2; ++diag) {
        int start_i = std::min(diag, n - 1);
        int start_j = diag - start_i;
        int length = std::min(diag + 1, 2 * n - 1 - diag);

        binary_indexed_tree bit(static_cast<size_t>(length));
        std::vector<int> range_down_left(length);
        std::vector<int> range_up_right(length);

        for (int t = 0; t < length; ++t) {
            range_down_left[t] = extend_down_left[start_i - t][start_j + t];
            range_up_right[t] = extend_up_right[start_i - t][start_j + t];
        }

        // counting sort events
        std::vector<std::pair<int, int>> events;
        {
            std::vector<int> counts(length, 1);
            for (int t = 0; t < length; ++t) {
                int down_left = range_down_left[t];
                if (t - down_left >= 0) {
                    counts[t - down_left]++;
                }
            }
            std::partial_sum(counts.begin(), counts.end(), counts.begin());
            events.resize(counts.back());
            for (int t = length - 1; t >= 0; --t) {
                int down_left = range_down_left[t];
                events[--counts[t]] = std::make_pair(t, t);
                if (t - down_left >= 0) {
                    events[--counts[t - down_left]] = std::make_pair(t - down_left, t);
                }
            }
            std::reverse(events.begin(), events.end());
        }

        for (const auto &event: events) {
            int t = event.first;
            int index = event.second;
            if (t == index) {
                int up_right = range_up_right[index];
                bit.modify(static_cast<size_t>(index + 1), +1);
                char c = grid[start_i - index][start_j + index];
                if (c - 'A' < k) {
                    answer[c - 'A'] += bit.query(static_cast<size_t>(index + up_right));
                }
            } else {
                bit.modify(static_cast<size_t>(index + 1), -1);
            }
        }
    }

    for (int i = 0; i < k; ++i) {
        std::cout << answer[i] << '\n';
    }

    return 0;
}
