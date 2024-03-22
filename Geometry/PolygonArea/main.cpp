#include <cstdint>
#include <iostream>
#include <vector>

struct Point
{
  Point() = default;

  Point(int64_t x_, int64_t y_)
      : x(x_)
      , y(y_)
  {
  }

  int64_t x{};
  int64_t y{};
};

auto operator>>(std::istream &input, Point &point) -> std::istream &
{
  return input >> point.x >> point.y;
}

auto main() -> int
{
  int n;
  std::cin >> n;
  std::vector<Point> points(n);
  for (auto &point : points)
  {
    std::cin >> point;
  }
  int64_t ans = 0;
  // shoelace formula https://en.wikipedia.org/wiki/Shoelace_formula
  for (int i = 0; i < n; i++)
  {
    ans += (points[i].x * points[(i + 1) % n].y - points[(i + 1) % n].x * points[i].y);
  }
  std::cout << (ans > 0 ? ans : -ans);
}
