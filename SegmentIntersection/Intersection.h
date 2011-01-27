/*
 * Intersection.h
 *
 * @author vh4x0r
 */

#ifndef __INTERSECTION_H__
#define __INTERSECTION_H__

#include "CompGeo.h"

double direction (const Point2D &, const Point2D &, const Point2D &);
bool onSegment (const Point2D &, const Point2D &, const Point2D &);
bool segmentsIntersect (const Line2D &, const Line2D &);
bool find (Point2D &, const Line2D &, const Line2D &);

#endif
