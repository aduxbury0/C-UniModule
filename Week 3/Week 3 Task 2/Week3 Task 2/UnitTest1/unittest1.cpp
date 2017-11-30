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
			

			string testNumber = "24553";
			string teststring = "thisisnotanumber";

			Assert::IsTrue(isNumber(testNumber));
			Assert::IsFalse(isNumber(teststring));

			vector<int> testvector = { 9,2,7,4 };
			int vectorsize = testvector.size();


			int target = 7;
			
			bool targetin = ListCheck(testvector, target, 0, testvector.size());

			Assert::IsTrue(targetin);


			

			



		}

	};
}