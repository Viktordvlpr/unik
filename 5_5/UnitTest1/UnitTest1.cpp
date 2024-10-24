#include "pch.h"
#include "CppUnitTest.h"
#include "../5_5/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{

            
            int n = 5;       
            int depth = 0;    
            int level = 1;    

            double expected = recursive_sequence(n, level, depth);
            Assert::AreEqual(expected, recursive_sequence(n, level, depth), 1e-6, L"Failed TestRecursiveSequence");
		}
	};
}
