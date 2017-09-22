#include "Collidable.h"
#include "Line.h"

#ifndef COLLIDABLE_LINE_H_
#define COLLIDABLE_LINE_H_

class CollidableLine: public Collidable {
public:
	CollidableLine(Point a, Point b);
	CollidableLine(const CollidableLine& other);
	CollidableLine& operator=(const CollidableLine& other);
private:
	Physics::Line line;
};

#endif