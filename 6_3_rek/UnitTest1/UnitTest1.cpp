#include "pch.h"
#include "CppUnitTest.h"
#include "../6_3_rek/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            const int size = 6; 
            int arr[size] = { 1, 2, 3, 4, 5, 6 }; 
            SwapEvenOddIndicesRecursive(arr, size);
            int expected[size] = { 2, 1, 4, 3, 6, 5 };

            for (int i = 0; i < size; i++) {
                Assert::AreEqual(expected[i], arr[i]);
            }
        }
    };
}