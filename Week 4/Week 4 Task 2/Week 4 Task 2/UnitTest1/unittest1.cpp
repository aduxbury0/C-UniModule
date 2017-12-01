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
			
			try {

				vector<int> testVector;
				for (int i = 0; i <= 120000; i++) {
					testVector.push_back(i);
				}

				numberGame(testVector);

			}

			catch(overflow_error) {

				Assert::Fail;

			}
		}

	};
}