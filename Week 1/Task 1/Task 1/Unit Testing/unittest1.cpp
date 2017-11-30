#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Source.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTesting
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			

			std::string testString1 = "Teststring";
			std::string testString2 = "ILoveTesting";

			std::string functionRes =  combineWords(testString1, testString2);

			Assert::IsTrue(functionRes == "TIeLsotvsetTreisntging");

		}
	};
}