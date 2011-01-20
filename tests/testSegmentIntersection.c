#include <stdio.h>
#include "CompGeo.h"
#include "SegmentIntersection.h"

int main () {
  Line2D l;
  initSegmentIntersection ();
  puts ("Input x1, y1, x2, y2 ...");
  do {
    scanf ("%lf %lf %lf %lf", &l.p1.x, &l.p1.y, &l.p2.x, &l.p2.y);
    if (l.p1.x == l.p2.x && l.p1.y == l.p2.y) break;
    addSegment (&l);
  } while (1);
  Point2DList p;
  findIntersection (&p);

  for (size_t i = 0; i < p.nPoints; i++)
   printf ("%lf, %lf\n", p.p[i].x, p.p[i].y);

  return 0;
}
