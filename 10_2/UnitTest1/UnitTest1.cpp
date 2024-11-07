#include "pch.h"
#include "CppUnitTest.h"
#include "../10_2/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest92B
{
	TEST_CLASS(UnitTest92B)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			const int N = 5;
			Student students[N] = {
				{"Smith", 2, CS, 80, 85, 90},
				{"Johnson", 3, INF, 75, 88, 92},
				{"Williams", 1, MATH, 70, 78, 85},
				{"Brown", 4, PHYS, 85, 82, 88},
				{"Jones", 2, HAND, 78, 80, 75}
			};
			Assert::IsTrue(binarySearch(students, 0, N - 1, CS, "Smith", 2));
			Assert::IsFalse(binarySearch(students, 0, N - 1, MATH, "Taylor", 3));
		}
	};
}
