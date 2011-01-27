/*
 * SegmentIntersection.h
 *
 * @author vh4x0r
 */

#ifndef __SEGMENTINTERSECTION_H__
#define __SEGMENTINTERSECTION_H__

#include <vector>
#include "CompGeo.h"

/* API */
void initSegmentIntersection (void);
void addSegment (const Line2D &);
void findIntersection (std::vector <Point2D> &);
void killSegmentIntersection (void);

static std::vector <Line2D> lines;

#endif
/* SegmentIntersection.h */
