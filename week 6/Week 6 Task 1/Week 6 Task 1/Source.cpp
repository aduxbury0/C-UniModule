
#include <iostream>
#include <string>

class BinTreeNode {
public:
	BinTreeNode(int value, BinTreeNode* inputParent) {
		this->value = value;
		this->left = nullptr;
		this->right = nullptr;

		if(inputParent == nullptr) {
			
			this->parent = nullptr;
		}
		else {

			this->parent = inputParent;
		}
		
		
	}

	~BinTreeNode() {
		std::cout << "NODE: " << value << " DELETED" << std::endl;
	}

	int value;
	BinTreeNode* left;
	BinTreeNode* right;
	BinTreeNode* parent;

};

BinTreeNode* tree_insert(BinTreeNode* tree, int item) {
	if (tree == nullptr)
		tree = new BinTreeNode(item, nullptr);
	else
		if (item < tree->value)
			if (tree->left == nullptr)
				tree->left = new BinTreeNode(item, tree);
			else
				tree_insert(tree->left, item);
		else
			if (tree->right == nullptr)
				tree->right = new BinTreeNode(item, tree);
			else
				tree_insert(tree->right, item);
	return tree;

}

void postorder(BinTreeNode* tree) {
	if (tree->left != nullptr)
		postorder(tree->left);
	if (tree->right != nullptr)
		postorder(tree->right);
	std::cout << tree->value << std::endl;

}

void in_order(BinTreeNode* tree) {
	if (tree->left != nullptr)
		in_order(tree->left);
	std::cout << tree->value << std::endl;
	if (tree->right != nullptr)
		in_order(tree->right);

}

BinTreeNode * searchTree(BinTreeNode* tree, int value) {

	if (tree->value != NULL) {

		if (value == tree->value) {

			return tree;
		}
		else if (value < tree->value & tree->left != nullptr) {

			tree = searchTree(tree->left, value);
			return tree;
		}

		else if (value > tree->value & tree->right != nullptr) {

			tree = searchTree(tree->right, value);
			return tree;
		}
		else {

			std::cout << "The value does not exist" << std::endl;
			return nullptr;
		}

	}
}
/* This is the method for deleting a node in a given tree 'tree' using the nodes value 'deletedValue'

inputs: Pointer to a Binary Tree Node type object, integer containig the value contained in the node that you wish to delete
outputs: none

*/
void delete_node(BinTreeNode* tree, int deletedValue) {

	tree = searchTree(tree, deletedValue);

	if (tree == NULL) {

		std::cout << "No value was deleted" << std::endl;
	}
	else if (tree->left == nullptr & tree->right == nullptr) { // delete a node with no children

		if (tree->value <= (tree->parent)->value) {
			(tree->parent)->left = nullptr;
		}
		else {
			(tree->parent)->right = nullptr;
		}

		delete tree;
	}
	
	else if(tree->left != nullptr & tree->right == nullptr) { // delete a node with only a left child
		tree->value = (tree->left)->value;
		BinTreeNode* holdingPointer = nullptr;
		if ((tree->left)->right != nullptr) { // if the node being copied has a right value then copy it to the left value of this node
			tree->right = (tree->left)->right;
		}
		if ((tree->left)->left != nullptr) { // if the node being copied has a left value then copy it to a holding variable until needed
			holdingPointer = (tree->left)->left;
		}

		delete tree->left;
		tree->left = holdingPointer; // replaces the deleted child with a pointer to its left child, if it had none then it will ensure that this is always a null pointer
	}
	
	else if (tree->right != nullptr & tree->left == nullptr) { // delete a node with only a right child
		tree->value = (tree->right)->value;
		BinTreeNode* holdingPointer = nullptr;
		if ((tree->right)->left != nullptr) { // if the node being copied has a left value then copy it to the left value of this node
			tree->left = (tree->right)->left;
		}
		if ((tree->right)->right != nullptr) { // if the node being copied has a right value then copy it to a holding variable until needed
			holdingPointer = (tree->right)->right;
		}
		delete tree->right;
		tree->right = holdingPointer; // replaces the deleted child with a pointer to its right child, if it had none then it will ensure that this is always a null pointer
	} 
	
	else if (tree->left != nullptr & tree->right != nullptr) { // delete a node with 2 children

		BinTreeNode* largestLeft = nullptr;
		
		while (largestLeft->right != nullptr) {
		
			largestLeft = largestLeft->right;
		}

		tree->value = largestLeft->value;
		delete_node(largestLeft, largestLeft->value);

	}
}

int main(int argc, char *argv[])
{
	BinTreeNode* t = tree_insert(0, 6);
	tree_insert(t, 10);
	tree_insert(t, 5);
	tree_insert(t, 2);
	tree_insert(t, 3);
	tree_insert(t, 4);
	tree_insert(t, 11);
	in_order(t);


	delete_node(t, 11);
	in_order(t);

	system("PAUSE");
	
	return 0;
}
