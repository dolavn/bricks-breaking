#pragma once

#include <string>

#ifndef VECTOR_H_
#define VECTOR_H_

namespace Physics {
	class Vector {
	public:
		static Vector getVectorCartesian(double x, double y);
		static Vector getVectorPolar(double size, double angle);
		Vector(const Vector& other);
		Vector();
		~Vector();
		double getX() const;
		double getY() const;
		double getSize() const;
		double getAngle() const;
		std::string toString() const;
		double getAngleWith(const Vector& other) const;

	private:
		const double x;
		const double y;
		double dotProduct(const Vector& other) const;
		Vector(double x, double y);
	};
}


#endif
