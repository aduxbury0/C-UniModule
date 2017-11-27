#include "Graph.h"



Graph::Graph()
{
}


Graph::~Graph()
{
}

void Graph::addVertex(int vertexValue) {


	adjacencyList.push_back(new Vertex(vertexValue));


}

void Graph::addEdge(int vertexFrom, int vertexTo) {

	for (int i = 0; i < adjacencyList.size(); i++) { // Searchs through the adjacency list looking for the initial Vertex that the edge will go from

		if (adjacencyList[i]->vertexValue == vertexFrom) { // When found it will search through the list again looking for the Vertex the edge will go to

			Vertex* vertexToPointer;

			for (int ii = 0; ii < adjacencyList.size(); ii++) {

				if (adjacencyList[ii]->vertexValue == vertexTo) {

					vertexToPointer = adjacencyList[ii];
					break;

				}
			}

			adjacencyList[i]->vectorOfEdges.push_back(vertexToPointer); // after both have been found they are added to eachothers lists of edges
			vertexToPointer->vectorOfEdges.push_back(adjacencyList[i]);
			break;

		}
	}
}

void Graph::printEdges(int vertexsEdges) {

	std::cout << "The edges for node: " << vertexsEdges << " are: ";

	for (int i = 0; i < adjacencyList.size(); i++) {

		if (adjacencyList[i]->vertexValue == vertexsEdges) {

			for (int ii = 0; ii < adjacencyList[i]->vectorOfEdges.size(); ii++) {
				std::cout << adjacencyList[i]->vectorOfEdges[ii]->vertexValue << " ";

			}

			break;

		}
	}



}
/* Method for checking whether an inputted Vertex has already been added to the class' vector 'visitedVerticies' 
- accepts a single pointer to a Vertex object and will return 'True' if it is in the vector or 'False' if it is not */
bool Graph::alreadyVisited(Vertex* inputVertex) { 

	for (int i = 0; i < visitedVerticies.size(); i++) {
	
		if (inputVertex == visitedVerticies[i]) {

			return true;

		}
	}

	return false;

}


/*Method for performing a Depth First Search traversal of the graph
- Accepts no inputs
- Will write each new node it visits to a text document */

void Graph::depthFirstSearch() {

	Vertex* currentVertex = adjacencyList[0]; // Starting the DFS at the first node in the Graphs vector, arbitrary starting point
	Vertex* nextVertex = nullptr;
	std::stack<Vertex*> vertexStack;
	bool loopContinue = true;
	visitedVerticies.clear(); // Making sure the visited vertices list is always clear when starting to traverse the graph
	std::ofstream DFSfile;
	DFSfile.open("DFS.txt");
	DFSfile.clear();


	while (loopContinue) {

		std::cout << "Current node being written to TXT file : " << currentVertex->vertexValue << std::endl;
		DFSfile << currentVertex->vertexValue << "\n";


		if (!alreadyVisited(currentVertex)) { // checking to see if the current node has already been searched, if it hasnt then it will be added to the stack and the first non searched
											  // member of it's vector of edges will be searched
			visitedVerticies.push_back(currentVertex);
			vertexStack.push(currentVertex);

			for (int i = 0; i < currentVertex->vectorOfEdges.size(); i++) { 

				if (!alreadyVisited(currentVertex->vectorOfEdges[i])) { // search through vector of edges for non visited edge

					currentVertex = currentVertex->vectorOfEdges[i];
					break;

				}

				else if (vertexStack.empty()) { // This will end the loop if the stack has been depleted
					loopContinue = false;
					break;

				}

				else {

					currentVertex = vertexStack.top(); // Popping the top of the stack if there are no unvisited edges
					vertexStack.pop();

				}
			}
		}

		else {

			break;

		}
	}
}

bool Graph::isPath(int startVertex, int endVertex) {

	bool startIsSubset = false;
	bool endIsSubset = false;


	for (int i = 0; i < adjacencyList.size(); i++) {

		if (adjacencyList[i]->vertexValue == startVertex) {

			startIsSubset = true;
		}

		if (adjacencyList[i]->vertexValue == endVertex) {

			endIsSubset = true;
		}

		if (startIsSubset == true & endIsSubset == true) {
			break;
		}
	}

	this->depthFirstSearch();

	for (int i = 0; i < visitedVerticies.size(); i++) {

		if (visitedVerticies[i]->vertexValue == startVertex) {

			startIsSubset = true;
		}

		if (visitedVerticies[i]->vertexValue == endVertex) {

			endIsSubset = true;
		}

		if (startIsSubset == true & endIsSubset == true) {
			return true;
		}
	}

	return false;

}