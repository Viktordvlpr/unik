#include "pch.h"
#include "CppUnitTest.h"
#include "../5_2/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double s; 
			int n;  
			double eps = 1e-6;  
			double x = 1.5;
			double result = S(x, eps, n, s);
			double expected = log(x);
			Assert::AreEqual(expected, result, 1e-5, L"Ошибка для S(1.5)");
		}
	};
}
