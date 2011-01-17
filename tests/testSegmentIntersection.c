#include <stdio.h>
#include "CompGeo.h"
#include "SegmentIntersection.h"

int main () {
  Line2D l[3];

  l[0].p1.x = 0; l[0].p1.y = 0;
  l[0].p2.x = 3; l[0].p2.y = 3;

  l[1].p1.x = 1; l[1].p1.y = 2;
  l[1].p2.x = 4; l[1].p2.y = 1;

  l[2].p1.x = 2; l[2].p1.y = 1;
  l[2].p2.x = 4; l[2].p2.y = 4;

  initSegmentIntersection ();
  addSegment (&l[0]);
  addSegment (&l[1]);
  addSegment (&l[2]);
  Point2DList p;
  findIntersection (&p);

  for (size_t i = 0; i < p.nPoints; i++)
   printf ("%lf, %lf\n", p.p[i].x, p.p[i].y);

  return 0;
}
