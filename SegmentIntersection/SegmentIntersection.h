/*
 * SegmentIntersection.h
 *
 * @author vh4x0r
 */

#ifndef __SEGMENTINTERSECTION_H__
#define __SEGMENTINTERSECTION_H__

#include <stddef.h>
#include "CompGeo.h"

/* API */
void initSegmentIntersection ();
void addSegment (const Line2D *);
void findIntersection (Point2DList *);
void killSegmentIntersection ();

static Line2D * line;
static size_t nLines;

#endif
/* SegmentIntersection.h */
