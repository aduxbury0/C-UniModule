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
			

			string word = "Testword";
			string expectedValue = "drowtseT";


			Assert::IsTrue(Mirroring(word, 0) == expectedValue);



		}

	};
}