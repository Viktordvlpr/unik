#include "pch.h"
#include "CppUnitTest.h"
#include "../7_1_it/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest71it
{
	TEST_CLASS(UnitTest71it)
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
			x[1][0] = -1;
			x[0][1] = -2;
			x[1][1] = 0;
			int S = 0;
			int k = 0;
			Calc(x, rowCount, colCount, S, k);
			for (int i = 0; i < rowCount; i++)
				delete[] x[i];
			delete[] x;

			Assert::AreEqual(k, 3);
			Assert::AreEqual(S, 1);
		}
	};
}
