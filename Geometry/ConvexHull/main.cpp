#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

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

auto main() -> int {
    int n;
    std::cin >> n;
    std::vector<Point> points(n);
    for (auto& point : points) {
        std::cin >> point;
    }
    std::ranges::sort(points);
    std::vector<Point> hull;
    size_t S{};
    for (int t = 0; t < 2; t++) {
        for (int i = 0; i < n; i++) {
            while (hull.size() >= 2 + S) {
                Point P1 = hull[hull.size() - 2];
                if (Point P2 = hull[hull.size() - 1]; P1.cross(P2, points[i]) <= 0) break;
                hull.pop_back();
            }
            hull.push_back(points[i]);
        }
        hull.pop_back();
        S = hull.size();
        std::ranges::reverse(points);
    }
    std::cout << S << '\n';
    for (auto const& point : hull) {
        std::cout << point.x << ' ' << point.y << '\n';
    }
}
