#include <cmath>
#include <cstdint>
#include <iostream>
#include <vector>

class Point
{
public:
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

/**
 * \brief Fetch the orientation of triplet (p, q and r)
 * \param point_p Point
 * \param point_q Point
 * \param point_r Point
 * \return 0, If the points p, q and r are collinear.
 * \       1, if the points are oriented clockwise.
 * \       2, if the points are oriented anticlockwise
 */
auto Get_Orientation(Point point_p, Point point_q, Point point_r) -> int
{
  const int64_t delta =
      (point_q.y - point_p.y) * (point_r.x - point_q.x) - (point_q.x - point_p.x) * (point_r.y - point_q.y);

  if (delta == 0)
    return 0;

  return (delta > 0) ? 1 : 2;
}

/**
 * \brief Check if point_r lies on the segment p-q.
 * \ If point_r lies on line p-q, then the x-coordinate of point_r should be between the x-coordinates of
 * \ point_p and point_q and the y-coordinate of point_r should be between the y-coordinates of point_p and
 * \ point_q.
 * \param point_p Point
 * \param point_q Point
 * \param point_r Point
 * \return true if point_r lies on the segment p-q.
 */
auto Check_On_Segment(Point point_p, Point point_q, Point point_r) -> bool
{
  if (point_r.x <= std ::max(point_p.x, point_q.x) && point_r.x >= std ::min(point_p.x, point_q.x)
      && point_r.y <= std ::max(point_p.y, point_q.y) && point_r.y >= std ::min(point_p.y, point_q.y))
  {
    return true;
  }
  return false;
}

/**
 * \brief Check intersect line segment at point (p1, q1) with line segment at point (p2, q2)
 * \param point_p1 first line Point
 * \param point_q1 first line Point
 * \param point_p2 second line Point
 * \param point_q2 second line Point
 * \return true if segments intersect
 */
auto Intersect(Point point_p1, Point point_q1, Point point_p2, Point point_q2) -> bool
{
  const int or_1 = Get_Orientation(point_p1, point_q1, point_p2);
  const int or_2 = Get_Orientation(point_p1, point_q1, point_q2);
  const int or_3 = Get_Orientation(point_p2, point_q2, point_p1);
  const int or_4 = Get_Orientation(point_p2, point_q2, point_q1);

  // General case : Points are non-collinear.
  if (or_1 != or_2 && or_3 != or_4)
    return true;

  // Special case : Points are collinear.

  // If points p1, q1 and p2 are collinear, check if point p2 lies on segment p1-q1
  if (or_1 == 0 && Check_On_Segment(point_p1, point_q1, point_p2))
    return true;

  // If points p1, q1 and q2 are collinear, check if point q2 lies on segment p1_q1
  if (or_2 == 0 && Check_On_Segment(point_p1, point_q1, point_q2))
    return true;

  // If points p2, q2 and p1 are collinear, check if point p1 lies on segment p2_q2
  if (or_3 == 0 && Check_On_Segment(point_p2, point_q2, point_p1))
    return true;

  // If points p2, q2 and q1 are collinear, check if point q1 lies on segment p2_q2
  if (or_4 == 0 && Check_On_Segment(point_p2, point_q2, point_q1))
    return true;

  return false;
}

auto main() -> int
{
  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i)
  {
    Point p1, q1, p2, q2;
    std::cin >> p1 >> q1 >> p2 >> q2;
    Intersect(p1, q1, p2, q2) ? puts("YES") : puts("NO");
  }
}
