#include <cstdint>
#include <iostream>

auto main() -> int
{
  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i)
  {
    int64_t x1, y1, x2, y2, x3, y3;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    if (const auto cross_product = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1); cross_product < 0)
    {
      puts("RIGHT");
    }
    else
    {
      cross_product > 0 ? puts("LEFT") : puts("TOUCH");
    }
  }
  return 0;
}
