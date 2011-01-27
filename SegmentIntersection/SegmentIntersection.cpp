/*
 * SegmentIntersection.c
 *
 * @author vh4x0r
 */

#include <vector>
#include "Intersection.h"
#include "SegmentIntersection.h"
using namespace std;

void initSegmentIntersection (void) {
  lines.clear ();
}

void addSegment (const Line2D & l) {
  lines.push_back (l);
}

void findIntersection (vector <Point2D> & points) {
  vector <Point2D>::size_type nLines = lines.size (), i, j;
  for (i = 0; i < nLines; i++)
    for (j = i+1; j < nLines; j++) {
      Point2D ip;
      if (find (ip, lines[i], lines[j]))
	points.push_back (ip);
    }
}

void killSegmentIntersection (void) {
  lines.clear ();
}
