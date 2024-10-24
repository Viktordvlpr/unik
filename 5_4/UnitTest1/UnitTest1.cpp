#include "pch.h"
#include "CppUnitTest.h"
#include "../5_4/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int k = 10;
			double expected = S0(k); 
			Assert::AreEqual(expected, S0(k), 1e-5, L"Failed TestS0");
		
		}
	};
}
