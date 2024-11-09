#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include <algorithm>
#include "Windows.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace SetOperationsTest
{
    TEST_CLASS(SetOperationsTests)
    {
    public:
        void performSetOperations(vector<int>& U, vector<int>& A, vector<int>& B,
            vector<int>& Abit, vector<int>& Bbit,
            vector<int>& notA, vector<int>& AperB,
            vector<int>& AobB, vector<int>& ArizB, vector<int>& AxorB)
        {
            int n = U.size();

            fill(Abit.begin(), Abit.end(), 0);
            fill(Bbit.begin(), Bbit.end(), 0);

            for (int i = 0; i < n; ++i) {
                if (find(A.begin(), A.end(), U[i]) != A.end()) {
                    Abit[i] = 1;
                }
                if (find(B.begin(), B.end(), U[i]) != B.end()) {
                    Bbit[i] = 1;
                }
            }

            for (int i = 0; i < n; ++i) {
                notA[i] = 1 - Abit[i];
                AperB[i] = Abit[i] & Bbit[i];
                AobB[i] = Abit[i] | Bbit[i];
                ArizB[i] = Abit[i] & ~Bbit[i];
                AxorB[i] = Abit[i] ^ Bbit[i];
            }
        }

        TEST_METHOD(TestSetOperations)
        {
            vector<int> U = { 1, 2, 3, 4, 5 };
            vector<int> A = { 1, 3, 5 };
            vector<int> B = { 2, 3, 4 };

            vector<int> Abit(U.size(), 0), Bbit(U.size(), 0);
            vector<int> notA(U.size(), 0), AperB(U.size(), 0), AobB(U.size(), 0), ArizB(U.size(), 0), AxorB(U.size(), 0);

            performSetOperations(U, A, B, Abit, Bbit, notA, AperB, AobB, ArizB, AxorB);

            Assert::AreEqual(Abit[0], 1); 
            Assert::AreEqual(Abit[1], 0); 
            Assert::AreEqual(Abit[2], 1); 
            Assert::AreEqual(Abit[3], 0); 
            Assert::AreEqual(Abit[4], 1); 

            Assert::AreEqual(Bbit[0], 0); 
            Assert::AreEqual(Bbit[1], 1); 
            Assert::AreEqual(Bbit[2], 1); 
            Assert::AreEqual(Bbit[3], 1); 
            Assert::AreEqual(Bbit[4], 0); 

            Assert::AreEqual(notA[0], 0); 
            Assert::AreEqual(AperB[0], 0); 
            Assert::AreEqual(AobB[0], 1); 
            Assert::AreEqual(ArizB[0], 1); 
            Assert::AreEqual(AxorB[0], 1); 

        }
    };
}
