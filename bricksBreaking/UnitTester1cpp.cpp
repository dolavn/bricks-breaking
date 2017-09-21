#include "stdafx.h"
#include "UnitTester1.h"
#include "Observer.h"
#include "UnitTester1.h"
#include "Line.h"
#include <sstream>
#include "Engine.h"
#include <iostream>

CircleColl::CircleColl(Point center, double radius) :Collidable(center, radius) {

}

void CircleColl::collide(Collidable& other) {

}

ConvColl::ConvColl(std::vector<Point> points) :Collidable(points) {

}

void ConvColl::collide(Collidable& other) {

}

int main(int argc, char **argv) {
	Engine e = Engine();
	e.startGame();
	return 0;

	/*
	using namespace Physics;

	Observer obs;
	CollisionDetector det(obs);
	CircleColl circ1(Point(0, 0), 1);
	CircleColl circ2(Point(1, 0), 1);
	std::vector<Point> points;
	std::vector<Point> points2;
	points.push_back(Point(1, 1));
	points.push_back(Point(5, 1));
	points.push_back(Point(2, 3));
	points2.push_back(Point(3, 3));
	points2.push_back(Point(4, 3));
	points2.push_back(Point(3, 3));
	ConvColl tri(points);
	ConvColl tri2(points2);
	//det.addCollidable(&circ1);
	//det.addCollidable(&circ2);
	det.addCollidable(&tri);
	det.addCollidable(&tri2);
	det.detectCollisions();
	/*
	std::cout << "Testing" << std::endl;
	Line a = Line(Point(2, 0), Point(2, 3));
	Line b = Line(Point(1, 1), Point(6, 6));
	std::stringstream ss;
	ss << "y=" << a.getM() << "x+" << a.getN();
	std::cout << ss.str() << std::endl;
	if (a.intersect(b)) {
		std::cout << "intersect" << std::endl;
	}
	else {
		std::cout << "doesn't intersect" << std::endl;
	}
	if (a.intersect(Point(4, 4), 2)) {
		std::cout << "intersect" << std::endl;
	}
	else {
		std::cout << "doesn't intersect" << std::endl;
	}
	if (b.intersect(Point(4, 4), 1)) {
		std::cout << "(1,1),(4,4) intersect" << std::endl;
	}
	else {
		std::cout << "doesn't intersect" << std::endl;
	}*//*
	int fin;
	std::cin >> fin;
	return 0;*/
}