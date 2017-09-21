#include "Collidable.h"

#include "Point.h"

#ifndef UNIT_TESTER_1_
#define UNIT_TESTER_1_

class CircleColl :public Collidable {
public:
	CircleColl(Point center, double radius);

	virtual void collide(Collidable& other);
private:
};

class ConvColl :public Collidable {
public:
	ConvColl(std::vector<Point> points);
	
	virtual void collide(Collidable& other);
};

int main(int argc, char** argv);

#endif