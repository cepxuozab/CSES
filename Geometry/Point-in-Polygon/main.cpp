#include <cstdint>
#include <deque>
#include <iostream>
#include <vector>

struct Point {
  Point() = default;

  Point(int64_t x_, int64_t y_) : x(x_), y(y_) {}

  auto operator+(const Point &b) const -> Point {
    return Point{x + b.x, y + b.y};
  }

  auto operator-(const Point &b) const -> Point {
    return Point{x - b.x, y - b.y};
  }

  auto operator*(const Point &b) const -> int64_t {
    return static_cast<int64_t>(x) * b.y - static_cast<int64_t>(y) * b.x;
  }

  void operator+=(const Point &b) {
    x += b.x;
    y += b.y;
  }

  void operator-=(const Point &b) {
    x -= b.x;
    y -= b.y;
  }

  void operator*=(const int k) {
    x *= k;
    y *= k;
  }

  [[nodiscard]] auto cross(const Point &b, const Point &c) const -> int64_t {
    return (b - *this) * (c - *this);
  }

  int64_t x{};
  int64_t y{};
};

auto operator>>(std::istream &input, Point &point) -> std::istream & {
  return input >> point.x >> point.y;
}

auto pointlineintersect(Point P1, Point P2, Point P3) -> bool {
  if (P2.cross(P1, P3) != 0)
    return false;
  return (std::min(P2.x, P3.x) <= P1.x && P1.x <= std::max(P2.x, P3.x)) &&
         (std::min(P2.y, P3.y) <= P1.y && P1.y <= std::max(P2.y, P3.y));
}

auto PointInPolygon(const std::deque<Point> &points) -> const char * {
  const size_t N = points.size() - 1;
  int cnt = 0;
  bool boundary = false;
  for (size_t i = 1; i <= N; i++) {
    size_t j = (i == N ? 1 : i + 1);
    if (pointlineintersect(points[0], points[i], points[j]))
      boundary = true;

    if ((points[i].x <= points[0].x && points[0].x < points[j].x &&
         points[0].cross(points[i], points[j]) < 0) ||
        (points[j].x <= points[0].x && points[0].x < points[i].x &&
         points[0].cross(points[j], points[i]) < 0))
      cnt++;
  }
  if (boundary)
    return "BOUNDARY";
  if (cnt & 1)
    return "INSIDE";
  return "OUTSIDE";
}

auto main() -> int {
  int n, m;
  std::cin >> n >> m;
  std::deque<Point> points(n);
  for (auto &point : points) {
    std::cin >> point;
  }
  for (int i = 0; i < m; ++i) {
    Point point;
    std::cin >> point;
    points.push_front(point);
    std::cout << PointInPolygon(points) << '\n';
    points.pop_front();
  }
}
