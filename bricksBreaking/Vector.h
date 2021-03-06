#include <string>
#include "Point.h"

#ifndef VECTOR_H_
#define VECTOR_H_

namespace Physics {
	/**
		A vector in the R2 vector space.

		@author Dolav Nitay
		@version 1.0
	*/
	class Vector {
	public:
		/**
			Returns a new vector, defined by cartesian coordinates.

			@param x The x coordinate of the vector
			@param y The y coordinate of the vector
			@return The vector defined by the cartesian coordinates (x,y)
		*/
		static Vector getVectorCartesian(double x, double y);
		/**
			Returns a new vector, defined by polar coordinates.

			@param size The size of the vector
			@param angle The angle the vector makes with the positive direction of the x axis
			@return The vector with the size and angle specified
		*/
		static Vector getVectorPolar(double size, double angle);
		/**
			Returns a new vector, the one that goes from one point to another

			@param a The first point
			@param b The second point
		*/
		static Vector getVectorPoints(Point a, Point b);
		/**
			Deep copies an existing vector

			@param other The other vector
		*/
		Vector(const Vector& other);
		/**
			Empty constructor, creates the zero vector
		*/
		Vector();
		/**
			Destroys this vector
		*/
		~Vector();
		/**
			Returns the x coordinate of this vector.

			@return The x coordinate of this vector
		*/
		double getX() const;
		/**
			Returns the y coordinate of this vector.

			@return The y coordinate of this vector
		*/
		double getY() const;
		/**
			Returns the size of this vector.

			@return The size of this vector
		*/
		double getSize() const;
		/**
			Returns the angle of this vector.

			@return The angle of this vector
		*/
		double getAngle() const;
		/**
			Returns a vector, with this vector's direction but with size 1.

			@return A vector, with this vector's direction, but with size 1.
		*/
		Vector getNormal() const;
		/**
			Returns a new vector, which is this vector, multiplied by a scalar size.

			@param scalar The scalar size.
			@return The vector, given by the multiplication of this vector and a scalar size.
		*/
		Vector multByScalar(double scalar) const;
		/**
			Returns a vector, which is this vector, roatated by a given angle.

			@param angle The rotation angle
			@return A vector, which is this vector rotated by a given angle.
		*/
		Vector rotate(double angle) const;
		/**
			Returns a string representation of this vector.

			@return A string representation of this vector
		*/
		std::string toString() const;
		/**
			Returns the angle this vector create with another vector.

			@param other The other vector
			@return The angle between this vector and another one.
		*/
		double getAngleWith(const Vector& other) const;
		/**
			Returns the dot product of this vector and another one.

			@param other The other vector
			@return The dot product of this vector and another one.
		*/
		double dotProduct(const Vector& other) const;
		/**
			Operator== returns true if and only if this object equals to one.

			@param rhs The object with which the comparision is done.
			@return True if and only this object equals to rhs.
		*/
		inline friend bool operator==(const Vector& rhs,const Vector& lhs);
	private:
		const double x; //The x coordinate of this vector
		const double y; //They y coordinate of the vector

		/**
			A private constructor, creates a new vector with the cartesian coordinates (x,y)

			@param x The x coordinate of the vector
			@param y The y coordinate of the vector
		*/
		Vector(double x, double y);
	};
}


#endif
