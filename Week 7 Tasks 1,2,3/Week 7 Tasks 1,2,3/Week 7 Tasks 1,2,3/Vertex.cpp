#include "Vertex.h"



Vertex::Vertex(int vertexInput)
{

	vertexValue = vertexInput;
	std::cout << "Node of value: " << vertexValue << " built" << std::endl;


}


Vertex::~Vertex()
{

	std::cout << "Node of the value: " << vertexValue << " has been deleted" << std::endl;

}

/*void Vertex::createEdge(Vertex* inputVertex, Vertex* edgeTo) {

	inputVertex->vectorOfEdges.push_back(edgeTo);


}

void Vertex::deleteEdge(Vertex* parentVertex, Vertex* vertexToDelete) {

	for (int i = 0; i < parentVertex->vectorOfEdges.size(); i++) {

		if (parentVertex->vectorOfEdges[i] == vertexToDelete) {

			parentVertex->vectorOfEdges.erase(parentVertex->vectorOfEdges.begin() + i);

		}



	}
}

*/