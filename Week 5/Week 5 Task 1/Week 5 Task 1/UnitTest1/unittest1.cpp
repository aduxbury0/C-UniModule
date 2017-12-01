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
			
			List* testList = new List();
			List * testList2 = testList;
			
			Node* testNode = new Node(5);
			
			testList->insert(0, testNode);
			testList->insert(testList->head, new Node(5));
			testList->insert(testList->head, new Node(7));
			testList->insert(testList->head, new Node(11));
			testList->insert(testList->head, new Node(15));
			testList->insert(testList->head, new Node(21));
			testList->insert(testList->head, new Node(7));
			testList->insert(testList->head, new Node(41));

			deleteDuplicates(testList);

			std::vector<int> numbersInList;

			Node* currentNode = testList->head;

			for (int i = 0; i < 8; i++) {

				numbersInList.push_back(currentNode->value);

				if (currentNode->next == nullptr) {
					break;
				}
				else {

					currentNode = currentNode->next;
				}

			}

			int sevens = 0;

			for (int i = 0; i < numbersInList.size(); i++) {

				if (numbersInList[i] == 7) {

					sevens++;

				}

			}

			if (sevens > 1) {

				Assert::Fail;

			}


		} //end of tests
	};
}