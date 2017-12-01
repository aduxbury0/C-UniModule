#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Source.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(NodeCreationCheck)
		{
			
			Graph testGraph;

			testGraph.addVertex(10);

			Assert::IsNotNull(testGraph.adjacencyList[0]); //testing that an object is created


		}

		TEST_METHOD(AddEdgeCheck) {


			Graph testGraph;

			testGraph.addVertex(10);
			testGraph.addVertex(15);
			testGraph.addEdge(10, 15);


			Assert::IsNotNull(testGraph.adjacencyList[0]->vectorOfEdges[0]);
			Assert::IsNotNull(testGraph.adjacencyList[1]->vectorOfEdges[0]);

		}


		TEST_METHOD(DFSCheck) {

			Graph testGraph; //creating a small graph structure

			testGraph.addVertex(10);
			testGraph.addVertex(15);
			testGraph.addVertex(5);
			testGraph.addVertex(8);

			testGraph.addEdge(10, 15);
			testGraph.addEdge(10, 5);
			testGraph.addEdge(10, 8);

			testGraph.depthFirstSearch(nullptr); //performing search, using the first item in the Vector belonging to testGraph, not a specific one

			int count;

			for (count = 0; count < testGraph.visitedVerticies.size(); count++) {

			}

			Assert::IsTrue(count == 4);


		}

		TEST_METHOD(IsPathCheck) {

			Graph testGraph; //creating a small graph structure

			testGraph.addVertex(10);
			testGraph.addVertex(15);
			testGraph.addVertex(5);
			testGraph.addVertex(8);

			testGraph.addEdge(10, 15);
			testGraph.addEdge(15, 5);

			bool connected = testGraph.isPath(10, 5);
			
			
			Assert::IsTrue(connected);




		}


	};
}