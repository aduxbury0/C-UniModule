#include "stdafx.h"
#include "Source.h"



void List::insert(Node* n, Node* x){

	if (n != 0) {
		x->next = n->next;
		n->next = x;
		x->prev = n;
		if (x->next != 0)
			x->next->prev = x;
	}
	if (this->head == 0) {
		this->head = x;
		this->tail = x;
		x->prev = 0;
		x->next = 0;
	}
	else if (this->tail == n) {
		this->tail = x;
	}
}


void List::nodeDelete(Node* x) {
	
	if (x->next == nullptr) { // Checks to see if the node is the last node in the list

		(x->prev)->next = nullptr;
		delete x;


	}
	else {

		(x->prev)->next = x->next; // sets the 'next' pointer of the previous node to be the location of the node after x
		(x->next)->prev = x->prev; // sets the 'prev' pointer of the next node to be the location of the node before x
		delete x; // deletes x
	}
}


void List::display() {
	
		Node* i = this->head;
		std::cout << "List: ";
		while (i != 0) {
			std::cout << i->value << ",";
			i = i->next;
		}
		std::cout << std::endl;
	
}

int main(int argc, char *argv[])
{
	List* l = new List();
	l->insert(0, new Node(4));
	l->insert(l->head, new Node(8));
	l->insert(l->head, new Node(8));
	l->insert(l->head, new Node(10));
	l->insert(l->head, new Node(11));
	l->insert(l->head, new Node(16));
	l->insert(l->head, new Node(6));
	l->insert(l->head, new Node(6));
	l->insert(l->head, new Node(1));
	l->display();
	

	deleteDuplicates(l);
	l->display();


	system("PAUSE");

	delete l;
	  
	return 0;
}


void deleteDuplicates(List* inputList) {

	Node* currentNode = inputList->head;

	while (currentNode->next != nullptr) { // outer loop that moved the current node pointer up the list

		Node* checkNode = currentNode;

		while (checkNode->next != nullptr) { // inner loop that moves the node that is being checked against the current node up the list

			checkNode = checkNode->next;

			if (currentNode->value == checkNode->value) {

				checkNode = checkNode->prev;
				inputList->nodeDelete(checkNode->next);

				}
			}
		
		if (currentNode->next != nullptr) {

			currentNode = currentNode->next;
		}	
	
	}
		
}

