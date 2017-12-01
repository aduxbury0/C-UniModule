#pragma once

#include <iostream>
#include <string>
#include <vector>



class Node
{
public:
	int value; 
	Node* next;
	Node* prev;
	Node(int val) {
		std::cout << "Node constructed!" << std::endl;
		this->value = val;
		this->next = (Node*)0;
		this->prev = (Node*)0;
	}
	~Node() {
				std::cout << "deleting node : " << this->value << std::endl;
	}
};

class List
{

public:
	Node* head;
	Node* tail;

	List() {
		std::cout << "List Constructor!" << std::endl;
		this->head = 0;
		this->tail = 0;
	}
	~List() {
		std::cout << "List destructor!" << std::endl;
	}
	
	void insert(Node*, Node*);
	void nodeDelete(Node*);
	void display();
};

void deleteDuplicates(List*);