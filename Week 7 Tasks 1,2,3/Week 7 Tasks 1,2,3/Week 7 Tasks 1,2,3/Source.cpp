#include <iostream>
#include <string>
#include <vector>
#include "Graph.h"


int main() {

	Graph newGraph;
	
	newGraph.addVertex(1);
	newGraph.addVertex(2);
	newGraph.addVertex(3);
	newGraph.addVertex(4);
	newGraph.addVertex(5);
	newGraph.addVertex(6);


	newGraph.addEdge(1, 2);
	newGraph.addEdge(1, 4);
	newGraph.addEdge(2, 3);
	newGraph.addEdge(2, 5);
	newGraph.addEdge(3, 5);
	newGraph.addEdge(4, 6);
	newGraph.addEdge(5, 6);
	newGraph.addEdge(5, 4);
	newGraph.addEdge(6, 1);

	std::cout << "Is there a path between node 1 and 6: " << newGraph.isPath(1, 6) << std::endl;

	system("PAUSE");
	

	return 0;
}