#include <vector>
#include <iostream>
#include <utility>

#include <algorithm>

struct Point {
    long long x{};
    long long y{};
};

struct Segment {
    Point start;
    Point end;
};

class Fenwick {
public:
    explicit Fenwick(std::size_t n = 0) : size_(n), bit_(n + 1) {}


    void add(int i, int delta) {
        for (; std::cmp_less_equal(i, size_); i += i & -i)
            bit_[i] += delta;
    }

    [[nodiscard]] auto sum(int i) const -> int {
        int res = 0;
        for (; i > 0; i -= i & -i)
            res += bit_[i];
        return res;
    }

private:
    std::size_t size_{};
    std::vector<int> bit_;
};

class RobotPath {
public:
    void solve() {
        readMoves();
        compressCoordinates();
        int firstCrossIndex = findFirstCrossing();
        long long result = computeAnswer(firstCrossIndex);
        std::printf("%lld\n", result);
    }

private:
    std::vector<Segment> segments_;
    std::vector<long long> coords_; // index -> original coordinate

    void readMoves() {
        int m;
        if (std::scanf("%d", &m) != 1) return;

        std::vector<std::pair<char, long long>> moves;
        moves.reserve(static_cast<std::size_t>(m));
        char buf[8];
        char last = 0;

        for (int i = 0; i < m; ++i) {
            long long d;
            if (std::scanf("%s%lld", buf, &d) != 2) break;
            char c = buf[0];

            if (!moves.empty() && moves.back().first == c) {
                moves.back().second += d;
                continue;
            }

            if ((c == 'U' && last == 'D') || (c == 'D' && last == 'U') ||
                (c == 'L' && last == 'R') || (c == 'R' && last == 'L')) {
                break;
            }

            moves.emplace_back(c, d);
            last = c;
        }

        Point cur{.x=0, .y=0};
        segments_.clear();
        segments_.push_back({cur, cur}); // dummy

        for (auto [dir, dist]: moves) {
            Point next = cur;
            switch (dir) {
                case 'U':
                    next.y += dist;
                    break;
                case 'D':
                    next.y -= dist;
                    break;
                case 'R':
                    next.x += dist;
                    break;
                case 'L':
                    next.x -= dist;
                    break;
                default:
                    break;
            }
            segments_.push_back({cur, next});
            cur = next;
        }
    }

    void compressCoordinates() {
        coords_.clear();
        coords_.reserve(segments_.size() * 4);
        coords_.push_back(std::numeric_limits<int>::min());

        for (auto const &s: segments_) {
            coords_.push_back(s.start.x);
            coords_.push_back(s.start.y);
            coords_.push_back(s.end.x);
            coords_.push_back(s.end.y);
        }

        std::ranges::sort(coords_);
        auto [first, last] = std::ranges::unique(coords_);
        coords_.erase(first, last);

        auto compress = [this](long long v) {
            return static_cast<int>(
                    std::ranges::distance(coords_.begin(), std::ranges::lower_bound(coords_, v)));
        };

        for (auto &s: segments_) {
            s.start.x = compress(s.start.x);
            s.start.y = compress(s.start.y);
            s.end.x = compress(s.end.x);
            s.end.y = compress(s.end.y);
        }
    }

    [[nodiscard]] auto checkCrossingUpTo(int m) const -> bool {
        int compN = static_cast<int>(coords_.size()) + 5;
        std::vector<std::vector<std::pair<int, int>>> updates(compN);
        std::vector<std::vector<std::pair<int, int>>> queries(compN);

        for (int i = 0; i <= m; ++i) {
            auto [x1, y1] = segments_[i].start;
            auto [x2, y2] = segments_[i].end;

            if (x2 < x1) std::swap(x1, x2);
            if (y2 < y1) std::swap(y1, y2);

            if (x1 == x2) {
                queries[x1].emplace_back(y1 - 1, -1);
                queries[x2].emplace_back(y2, +1);
            }
            if (y1 == y2) {
                updates[x1].emplace_back(y1, +1);
                if (x2 + 1 < compN)
                    updates[x2 + 1].emplace_back(y2, -1);
            }
        }

        Fenwick fenw(coords_.size() + 5);
        int intersections = -2;

        for (int x = 0; x < compN && intersections < m; ++x) {
            for (auto [yIdx, delta]: updates[x])
                fenw.add(yIdx, delta);

            for (auto [yIdx, coeff]: queries[x]) {
                int cnt = fenw.sum(yIdx);
                intersections += coeff * cnt;
            }
        }
        return intersections >= m;
    }

    [[nodiscard]] auto findFirstCrossing() const -> int {
        int l = 0, r = static_cast<int>(segments_.size()) - 1, ans = r + 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (checkCrossingUpTo(mid)) {
                ans = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        return ans;
    }

    [[nodiscard]] auto coordDiff(int a, int b) const -> long long {
        return std::llabs(coords_[a] - coords_[b]);
    }

    [[nodiscard]] auto computeAnswer(int firstCross) const -> long long {
        long long total = 0;
        int n = static_cast<int>(segments_.size());

        for (int i = 0; i < firstCross && i < n; ++i) {
            auto const &s = segments_[i];
            total += coordDiff(s.start.x, s.end.x);
            total += coordDiff(s.start.y, s.end.y);
        }

        if (firstCross != n) {
            auto [x1, y1] = segments_[firstCross].start;
            auto [x2, y2] = segments_[firstCross].end;

            bool vertical = (x1 == x2);
            if (vertical) {
                std::swap(x1, y1);
                std::swap(x2, y2);
            }

            long long bestExtra = LLONG_MAX;

            for (int i = 0; i < firstCross - 1; ++i) {
                auto [a1, b1] = segments_[i].start;
                auto [a2, b2] = segments_[i].end;
                if (vertical) {
                    std::swap(a1, b1);
                    std::swap(a2, b2);
                }

                if (std::max(a1, a2) < std::min(x1, x2) ||
                    std::max(x1, x2) < std::min(a1, a2) ||
                    std::max(y1, y2) < std::min(b1, b2) ||
                    std::max(b1, b2) < std::min(y1, y2))
                    continue;

                long long candidate = std::llabs(coords_[x1] - coords_[a1]);
                bestExtra = std::min(bestExtra, candidate);
            }

            if (bestExtra != LLONG_MAX)
                total += bestExtra;
        }

        return total;
    }
};

auto main() -> int {
    RobotPath().solve();
    return 0;
}
