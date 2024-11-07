



#include "pch.h"
#include "CppUnitTest.h"
#include "../6_4_it/Source.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			const int size = 10;
			const double arr[size] = { 34,54,68,-24,57,45,67,34,-57,34 };
			int sum = SumAfterLastNegative(arr, size);
			Assert::AreEqual(sum, 34);

		}
	};
}