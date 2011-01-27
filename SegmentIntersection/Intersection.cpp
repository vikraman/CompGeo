/*
 * Intersection.cpp
 *
 * @author vh4x0r
 */

#include <algorithm>
#include "Intersection.h"
#include "CompGeo.h"
using namespace std;

double direction (const Point2D & p1, const Point2D & p2, const Point2D & p0) {
  return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

bool onSegment (const Point2D & pi, const Point2D & pj, const Point2D & pk) {
  if (min (pi.x, pj.x) <= pk.x && pk.x <= max (pi.x, pj.x) && min (pi.y, pj.y) <= pk.y && pk.y <= max (pi.y, pj.y))
    return true;
  return false;
}

bool segmentsIntersect (const Line2D & l1, const Line2D & l2) {
  double d1 = direction (l2.p1, l2.p2, l1.p1);
  double d2 = direction (l2.p1, l2.p2, l1.p2);
  double d3 = direction (l1.p1, l1.p2, l2.p1);
  double d4 = direction (l1.p1, l1.p2, l2.p2);
  if (((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) && ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0)))
    return true;
  else if (d1 == 0 && onSegment (l2.p1, l2.p2, l1.p1))
    return true;
  else if (d2 == 0 && onSegment (l2.p1, l2.p2, l1.p2))
    return true;
  else if (d3 == 0 && onSegment (l1.p1, l1.p2, l2.p1))
    return true;
  else if (d4 == 0 && onSegment (l1.p1, l1.p2, l2.p2))
    return true;
  return false;
}

bool find (Point2D & p, const Line2D & l1, const Line2D & l2) {
  if (!segmentsIntersect (l1, l2)) return false;
  double m1 = (l1.p2.y - l1.p1.y) / (l1.p2.x - l1.p1.x);
  double m2 = (l2.p2.y - l2.p1.y) / (l2.p2.x - l2.p1.x);
  p.x = (l1.p1.y - l2.p1.y + l2.p1.x * m2 - l1.p1.x * m1) / (m2 - m1);
  p.y = ((l2.p1.x - l1.p1.x) * m1 * m2 + l1.p1.y * m2 - l2.p1.y * m1) / (m2 - m1);
  return true;
}
