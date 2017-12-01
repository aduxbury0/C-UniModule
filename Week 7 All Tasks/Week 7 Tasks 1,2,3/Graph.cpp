#include "stdafx.h"
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

void Graph::depthFirstSearch(Vertex* inputNode) {

	Vertex* currentVertex = inputNode;

	if (inputNode == nullptr) { // allows you to enter a null ptr as an arguement to let the function start from the beginning of the adjacency list

		currentVertex = adjacencyList[0]; // Starting the DFS at the first node in the Graphs vector, arbitrary starting point

	}

	std::stack<Vertex*> vertexStack;
	bool loopContinue = true;
	visitedVerticies.clear(); // Making sure the visited vertices list is always clear when starting to traverse the graph
	std::ofstream DFSfile; // creating the object to deal with writing the text document
	DFSfile.open("DFS.txt");
	DFSfile.clear(); //opening and clearing the document, ready for use


	while (loopContinue) {

		if (!alreadyVisited(currentVertex)) { // Will print each unique node it comes accross (One that is not already visited) & add it to visited list

			visitedVerticies.push_back(currentVertex);

			std::cout << "Current node being written to TXT file : " << currentVertex->vertexValue << std::endl;
			DFSfile << currentVertex->vertexValue << "\n";

		}
		

		for (int i = 0; i < currentVertex->vectorOfEdges.size(); i++) { // search through vector of edges for non visited edge

			if (!alreadyVisited(currentVertex->vectorOfEdges[i])) { // Found a non-visited edge



				vertexStack.push(currentVertex);
				currentVertex = currentVertex->vectorOfEdges[i];

				break;

			}

			else if (vertexStack.empty() & i == currentVertex->vectorOfEdges.size()-1) { // This will end the loop if the stack has been depleted
				loopContinue = false;
				break;

			}

			else if(i == currentVertex->vectorOfEdges.size()-1) {

				currentVertex = vertexStack.top(); // Popping the top of the stack if there are no unvisited edges
				vertexStack.pop();
				


			}
		}
	}
}


/* Method for checking whether a path exists between 2 points

inputs: integer value of the node you wish to travel from, integer value of the node you wish to travel to
outputs: true if there is a path, false if there is not*/

bool Graph::isPath(int startVertex, int endVertex) {

	bool startIsSubset = false;
	bool endIsSubset = false;

	Vertex* startVertexLocation = nullptr;

	for (int i = 0; i < adjacencyList.size(); i++) { // For loop that checks that both the start and end nodes are a subset of the overall graph

		if (adjacencyList[i]->vertexValue == startVertex) { // start is a subset

			startIsSubset = true;
			startVertexLocation = adjacencyList[i];


		}

		if (adjacencyList[i]->vertexValue == endVertex) { // end is a subset

			endIsSubset = true;
		}

		if (startIsSubset == true & endIsSubset == true) { // will break from the loop if both are found for efficiancy
			break;
		}
	}

	if (startIsSubset == false | endIsSubset == false) { // if one or both are not part of the graph then they are not connected

		return false;

	}

	//uses the depth first search to traverse the graph that is connected to the root, it saves all visited Verticies in a public member vector
	this->depthFirstSearch(startVertexLocation); //makes use of the changeable start location of the DFS and starts it at the starting Vertex

	startIsSubset = false;
	endIsSubset = false;

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