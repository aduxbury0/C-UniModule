#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Source.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			
			std::vector<int> polynomial1 = { 1,3 };
			std::vector<int> polynomial2 = { 1,2 };
			int degree1 = polynomial1.size() - 1;
			int degree2 = polynomial2.size() - 1;

			std::vector<int> testVector = {1,5,6};
			std::vector<int> testReturnVector = PolyMulti(degree1, degree2, polynomial1, polynomial2);

			for (int i = 0; i < testVector.size(); i++) {

				Assert::IsTrue(testReturnVector[i] == testVector[i]);

			}
		}
	};
}