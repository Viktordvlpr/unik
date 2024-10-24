#include "pch.h"
#include "CppUnitTest.h"
#include "../5_1/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(1.0, g(0, 1), L"g(0, 1) должно быть равно 1");
		}
	};
}
