#pragma once

#include <iostream>
#include <string>
#include <vector>

#ifndef Vertex_H
#define Vertex_H

class Vertex
{
public:

	int vertexValue;
	std::vector<Vertex*> vectorOfEdges;

	Vertex(int);
	~Vertex();

//	void createEdge(Vertex*, Vertex*);
//	void deleteEdge(Vertex*, Vertex*);



};


#endif //!Vertex_H