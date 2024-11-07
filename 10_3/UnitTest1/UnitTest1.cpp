#include "pch.h"
#include "CppUnitTest.h"
#include "../10_3/Source.cpp"
using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest93
{
    TEST_CLASS(UnitTest93)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            Price testArray[4];
            testArray[0] = { "Product1", "ShopC", 100.0 };
            testArray[1] = { "Product2", "ShopA", 200.0 };
            testArray[2] = { "Product3", "ShopD", 300.0 };
            testArray[3] = { "Product4", "ShopB", 400.0 };

            SortByShopName(testArray, 4);

            Assert::AreEqual("ShopA", testArray[0].shopName.c_str());
            Assert::AreEqual("ShopB", testArray[1].shopName.c_str());
            Assert::AreEqual("ShopC", testArray[2].shopName.c_str());
            Assert::AreEqual("ShopD", testArray[3].shopName.c_str());
        }
    };
}
