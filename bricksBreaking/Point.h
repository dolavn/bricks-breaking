#pragma once

class Point {
public:
	Point(int x, int y);
	Point(const Point& other);
	Point& operator=(const Point& other);
	int getX() const;
	int getY() const;
private:
	int x;
	int y;
};