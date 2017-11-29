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
