#include "pch.h"
#include "CppUnitTest.h"
#include "../5_3/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(f(1.0), (sin(1.0) * sin(1.0) + sin(1.0 * 1.0)) / (1 + cos(1.0) * cos(1.0)), 0.001, L"Error in f(1.0)");
		}
	};
}
