#include "pch.h"
#include "CppUnitTest.h"
#include "../7_3_it/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest73rek
{
	TEST_CLASS(UnitTest73rek)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int rowCount = 2;
			int colCount = 2;

			int** x = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				x[i] = new int[colCount];
			x[0][0] = 2;
			x[0][1] = 2;
			x[1][0] = 2;
			x[1][1] = 1;
			int columnWithMaxSeries = -1;
			findLongestSeriesColumnRecursive(x, 0, 0, rowCount, colCount, columnWithMaxSeries, 0, 0);
			Assert::AreEqual(columnWithMaxSeries, 0);
		}
	};
}
