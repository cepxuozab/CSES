#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <set>
#include <vector>
#include <climits>

struct Point {
    Point() = default;

    Point(int64_t x_, int64_t y_)
        : x(x_)
        , y(y_) {
    }

    auto operator+(const Point& b) const -> Point {
        return Point{x + b.x, y + b.y};
    }

    auto operator-(const Point& b) const -> Point {
        return Point{x - b.x, y - b.y};
    }

    auto operator*(const Point& b) const -> int64_t {
        return static_cast<int64_t>(x) * b.y - static_cast<int64_t>(y) * b.x;
    }

    void operator+=(const Point& b) {
        x += b.x;
        y += b.y;
    }

    void operator-=(const Point& b) {
        x -= b.x;
        y -= b.y;
    }

    void operator*=(const int k) {
        x *= k;
        y *= k;
    }

    [[nodiscard]] auto cross(const Point& b, const Point& c) const -> int64_t {
        return (b - *this) * (c - *this);
    }
    auto operator<=>(Point const&) const = default;

    int64_t x{};
    int64_t y{};
};

auto operator>>(std::istream& input, Point& point) -> std::istream& {
    return input >> point.x >> point.y;
}
auto norm(Point a, Point b) -> int64_t {
    return (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
}

auto main() -> int {
    int n;
    std::cin >> n;
    std::vector<Point> points(n);
    for (auto& point : points) {
        std::cin >> point;
    }
    std::ranges::sort(points);
    Point start{points.front().y, points.front().x};
    std::set<Point> sets{start};
    int j = 0;
    int64_t d = LLONG_MAX;
    for (int i = 1; i < n; i++) {
        int64_t const dd = ceil(sqrt(d));
        while (j < i && points[j].x < points[i].x - dd) {
            sets.erase({points[j].y, points[j].x});
            j++;
        }
        auto l = sets.lower_bound({points[i].y - dd, 0});
        auto r = sets.upper_bound({points[i].y + dd, 0});
        for (auto it = l; it != r; ++it) {
            d = std::min(d, norm({it->y, it->x}, points[i]));
        }
        sets.insert({points[i].y, points[i].x});
    }
    std::cout << d;
}
