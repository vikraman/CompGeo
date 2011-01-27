#include <cstdio>
#include <vector>
#include "CompGeo.h"
#include "SegmentIntersection.h"

int main () {
  Line2D l;
  initSegmentIntersection ();
  puts ("Input x1, y1, x2, y2 ...");
  do {
    scanf ("%lf %lf %lf %lf", &l.p1.x, &l.p1.y, &l.p2.x, &l.p2.y);
    if (l.p1.x == l.p2.x && l.p1.y == l.p2.y) break;
    addSegment (l);
  } while (1);

  std::vector <Point2D> p;
  findIntersection (p);

  for (size_t i = 0; i < p.size (); ++i)
    printf ("%lf, %lf\n", p[i].x, p[i].y);

  killSegmentIntersection ();
  return 0;
}
