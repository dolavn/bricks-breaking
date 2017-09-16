#include "stdafx.h"
#include "UnitTester1.h"

#include "Line.h"
#include "Point.h"
#include <sstream>

#include <iostream>

int main(int argc, char **argv) {
	using namespace Physics;
	std::cout << "Testing" << std::endl;
	Line a = Line(Point(0, 0), Point(3, 1));
	Line b = Line(Point(2, 0), Point(3, 3));
	std::stringstream ss;
	ss << "y=" << a.getM() << "x+" << a.getN();
	std::cout << ss.str() << std::endl;
	if (!a.intersect(b)) {
		std::cout << "not good" << std::endl;
	}
	int fin;
	std::cin >> fin;
	return 0;
}