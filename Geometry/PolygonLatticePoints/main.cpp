#include <algorithm>
#include <cstdint>
#include <iostream>
#include <numeric>
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
    points.push_back(points.front());
    int64_t area{};
    for (int i = 0; i < n; i++) {
        area += points[i].x * points[i + 1].y;
        area -= points[i].y * points[i + 1].x;
    }
	 //pick's theorem + https://math.stackexchange.com/a/301895/530789
    area = area > 0 ? area : -area;
    int64_t boundary{};
    for (int i = 0; i < n; i++) {
        auto const X1 = points[i + 1].x - points[i].x;
        auto const Y1 = points[i + 1].y - points[i].y;
        if (X1 == 0)
            boundary += llabs(Y1);
        else if (Y1 == 0)
            boundary += llabs(X1);
        else
            boundary += std::gcd(llabs(X1), llabs(Y1));
    }
    std::cout << (area + 2 - boundary) / 2 << ' ' << boundary << '\n';
}
