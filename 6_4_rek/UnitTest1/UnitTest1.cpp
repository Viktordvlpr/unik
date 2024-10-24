#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include <algorithm>
#include "../6_4_rek/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:
        TEST_METHOD(TestCountLessThanC)
        {
            std::vector<double> arr = { 1.0, 2.5, 3.0, 0.5, 4.5 };
            double C = 2.0;
            int count = countLessThanC(arr, C, 0);
            Assert::AreEqual(count, 2); 
        }

    };
}
