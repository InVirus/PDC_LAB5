#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include <string>
#include "../PDC_LAB_5_1/source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            vector<string> expected = {
                "x0a", "x0b", "x0c",
                "x1a", "x1b", "x1c",
                "y0a", "y0b", "y0c",
                "y1a", "y1b", "y1c",
                "z0a", "z0b", "z0c",
                "z1a", "z1b", "z1c"
            };

            vector<string> result = generateCombinations();

            for (size_t i = 0; i < expected.size(); ++i) {
                Assert::AreEqual(expected[i].c_str(), result[i].c_str(), L"Результат не відповідає очікуваному");
            }
        }
    };
}
