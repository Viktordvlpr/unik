#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include "../8_2/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest82
{
    TEST_CLASS(UnitTest82)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            string inputString1 = "This is a test string.";
            string inputString2 = "Short string.";
            string inputString3 = "A B C D E F";

            size_t result1 = MinLength(inputString1);
            size_t result2 = MinLength(inputString2);
            size_t result3 = MinLength(inputString3);

            Assert::AreEqual(static_cast<size_t>(1), result1);
            Assert::AreEqual(static_cast<size_t>(5), result2);
            Assert::AreEqual(static_cast<size_t>(1), result3);
        }
    };
}
