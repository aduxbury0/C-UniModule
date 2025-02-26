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
			
			string testString1 = "371"; // should return true
			string testString2 = "124"; // should return false

			Assert::IsTrue(isArmstrong(testString1));
			Assert::IsFalse(isArmstrong(testString2));

		}

	};
}