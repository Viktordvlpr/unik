#include "pch.h"
#include "CppUnitTest.h"
#include "../6_4_it/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

extern double* CreateArray(int size);
extern int CountElementsLessThanC(double* arr, int size, double C);
extern double SumOfIntegersAfterLastNegative(double* arr, int size);
extern double FindMaxElement(double* arr, int size);
extern void TransformArray(double* arr, int size);

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestCountElementsLessThanC)
		{

			double arr[] = { 1.5, -3.7, 4.2, 10.0, 5.8 };
			int size = 5;
			double C = 5.0;

			int expectedCount = 3;

			int actualCount = CountElementsLessThanC(arr, size, C);

			Assert::AreEqual(expectedCount, actualCount);
		}
	};
}