#include "pch.h"
#include "CppUnitTest.h"
#include "../6_2_it/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            const int size = 10;
            int arr[size] = { 23, 43, 56, 34, 24, 65, 76, 34, 56, 88 };


            int expectedMaxIdx = 9; 
            int expectedMinIdx = 0; 
            int expectedSum = expectedMaxIdx + expectedMinIdx;

            int actualSum = SumIndices(arr, size);
            Assert::AreEqual(expectedSum, actualSum);
        }
    };
}