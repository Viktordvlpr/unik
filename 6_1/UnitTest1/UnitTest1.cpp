#include "pch.h"
#include "CppUnitTest.h"
#include "../6_1/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTest)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            const int size = 21;
            int b[size] = { 49, 83, 55, 39, 20, 47, 33, 46, 83, 76, 35, 29, 27, 39, 53, 76, 39, 27, 19, 53, 19 };

            int count = 0;
            ReplaceElements(b, size, count);

            Assert::AreEqual(b[7], 0);  
            Assert::AreEqual(b[9], 0);  
            Assert::AreEqual(b[15], 0); 
            Assert::AreEqual(b[14], 0); 



            /*Assert::AreEqual(count, 4);*/
        }
    };
}
