/*
 * CompGeo.h
 *
 * @author vh4x0r
 */

#ifndef __COMPGEO_H__
#define __COMPGEO_H__

#include <stddef.h>

typedef struct _Point2D {
  double x;
  double y;
} Point2D;

typedef struct _Line2D {
  Point2D p1;
  Point2D p2;
} Line2D;

#endif
/* CompGeo.h */
