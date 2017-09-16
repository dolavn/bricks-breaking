#include "stdafx.h"
#include "UnitTester1.h"

#include "Line.h"
#include "Point.h"
#include <sstream>
#include "Engine.h"
#include <iostream>

int main(int argc, char **argv) {
	/*Engine e = Engine();
	e.startGame();
	return 0;*/

	
	using namespace Physics;
	std::cout << "Testing" << std::endl;
	Line a = Line(Point(2, 0), Point(2, 3));
	Line b = Line(Point(1, 1), Point(3, 3));
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
		std::cout << "(1,1),(3,3) intersect" << std::endl;
	}
	else {
		std::cout << "doesn't intersect" << std::endl;
	}
	int fin;
	std::cin >> fin;
	return 0;
}