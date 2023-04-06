#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_12_3_Recur/Lab_12_3_Recur.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab123Recur
{
	TEST_CLASS(UnitTestLab123Recur)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* L1 = NULL, * last1 = NULL, * L2 = NULL, * last2 = NULL;
			LAdd(L1, last1, 6, 13, 1);
			LAdd(L2, last2, 0, 16, 1);
			Assert::IsTrue(LisSubset(L2, L1, L2, false));
		}
	};
}
