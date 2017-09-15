#include "stdafx.h"
#include "CppUnitTest.h"
#include "targetver.h"
#include "../bricksBreaking/Line.cpp"
#include "../bricksBreaking/Point.cpp"
#include "../bricksBreaking/Vector.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			using namespace Physics;
			Line a = Line(Point(0, 0),Point(1, 1));
			Assert::AreEqual(a.getM(), 1.0);
			Assert::AreEqual(a.getN(), 0.0);
			Vector v = a.getVector();
			Vector v2 = Vector::getVectorCartesian(1, 1);
			Assert::AreEqual(v.getX(), v2.getX());
			Assert::AreEqual(v.getY(), v2.getY());
			a = Line(Point(0, 5), Point(1, 5));
			Vector v3 = a.getVector();
			Vector v4 = Vector::getVectorCartesian(1, 0);
			Assert::AreEqual(v3.getX(), v4.getX());
			Assert::AreEqual(v3.getY(), v4.getY());
			Assert::AreEqual(a.getM(), 0.0);
			Assert::AreEqual(a.getN(), 5.0);
			a = Line(Point(1, 0), Point(1, 1));
			Logger::WriteMessage("" + a.isVertical());
			Assert::AreEqual(a.isVertical(), true);
		}

	};
}