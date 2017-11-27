#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <fstream>
#include "Vertex.h"

#ifndef Graph_H
#define Graph_H


class Graph
{
public:

	std::vector<Vertex*> adjacencyList;
	std::vector<Vertex*> visitedVerticies;

	Graph();
	~Graph();
	void addVertex(int);
	void addEdge(int, int);
	void printEdges(int);
	bool alreadyVisited(Vertex*);
	void depthFirstSearch();
	bool isPath(int, int);

};

#endif // !Graph_H