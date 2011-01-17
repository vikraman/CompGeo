/*
 * SegmentIntersection.c
 *
 * @author vh4x0r
 */

#include <stdlib.h>
#include "SegmentIntersection.h"

void initSegmentIntersection (void) {
  line = NULL;
  nLines = 0;
}

void addSegment (const Line2D * l) {
  nLines++;
  line = realloc (line, nLines * sizeof (Line2D));
  line[nLines - 1] = *l;
}

static void find (Point2D * p, const Line2D * l1, const Line2D * l2) {
  double m1 = (l1->p2.y - l1->p1.y) / (l1->p2.x - l1->p1.x);
  double m2 = (l2->p2.y - l2->p1.y) / (l2->p2.x - l2->p1.x);
  if (m1 == m2)
    { p = NULL; return; }
  p -> x = (l1->p1.y - l2->p1.y + l2->p1.x * m2 - l1->p1.x * m1) / (m2 - m1);
  p -> y = ((l2->p1.x - l1->p1.x) * m1 * m2 + l1->p1.y * m2 - l2->p1.y * m1) / (m2 - m1);
}

void findIntersection (Point2DList * pList) {
  pList->nPoints = 0;

  for (size_t i = 0; i < nLines; i++)
    for (size_t j = i+1; j < nLines; j++)
      {
	Point2D * ip = malloc (sizeof (Point2D));
	find (ip, &line[i], &line[j]);
	if (ip == NULL) continue;
	pList->nPoints++;
	pList->p = realloc (pList -> p, pList->nPoints * sizeof (Point2D));
	pList->p[pList->nPoints - 1] = *ip;
	free (ip);
      }
}
