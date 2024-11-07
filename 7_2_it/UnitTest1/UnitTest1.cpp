#include "pch.h"
#include "CppUnitTest.h"
#include "../7_2_it/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest72it
{
	TEST_CLASS(UnitTest72it)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int rows = 3;
			int cols = 3;
			int** matrix = new int* [rows];
			for (int i = 0; i < rows; i++) {
				matrix[i] = new int[cols];
			}
			matrix[0][0] = 1;
			matrix[1][0] = -2;
			matrix[2][0] = 5;

			matrix[0][1] = 2;
			matrix[1][1] = 3;
			matrix[2][1] = 1;

			matrix[0][2] = -3;
			matrix[1][2] = 0;
			matrix[2][2] = 4;

			int minInEvenCol = FindMinInEvenColumn(matrix, rows, cols, 2);
			Assert::AreEqual(minInEvenCol, -3);

			for (int i = 0; i < rows; i++) {
				delete[] matrix[i];
			}
			delete[] matrix;
		}
	};
}
