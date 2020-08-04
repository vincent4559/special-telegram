#pragma once
#pragma once
/*
Adam Kuhnel
vak58
MWF 3:30 - 5
This program creates a avl using nodes */

#pragma once
#include <iostream>
#include <fstream>
#include <vector>
using std::ofstream;
using namespace std;
#include <string>
#include <stack>
using std::ostream;
using std::string;


//Create node class for avl, left and right child.
class Node
{
public:
	string data;
	Node* left;
	Node* right;
	Node* parent;
	int bf;
	Node() {
		left = nullptr;
		parent = nullptr;
		right = nullptr;
		bf = 0;
	}
	Node(string data, Node* left = nullptr, Node* right = nullptr) {
		this->data = data;
		this->left = left;
		this->parent = parent;
		this->bf = bf;
		this->right = right;

	}
};


//Create class for bst.
class Tree {
private:
	Node* root;

public:
	Tree()
	{
		root = nullptr;
	}

	//Use two functions to pass in root, so user cannot directly tamper with root.
	void inOrder(ostream& os) {
		InOrder(root, os);
	}

	bool search(string data) {
		return Search(root, data);
	}
	bool Insert(string data) {
		return insert(root, data);
	};
	void preOrder(ostream& os) {
		PreOrder(root, os);
	};

	void postOrder(ostream& os) {
		PostOrder(root, os);
	};
	void postfileorder(ofstream& ofs) {
		PostFileOrder(root, ofs);
	}
	void del(string str) {
		Del(root, str);
	}
	void clear() {
		Clear(root);
	}
	void checkBalance() {
		CheckBalance(root);
	}
	void printBalance(ostream& os) {
		PrintBalance(root, os);
	}
	void fileInsert(vector<string>& l, int size) {
		FileInsert(root, l, size);
	}






	bool insert(Node*& n, string data) {

		//Set root initializations
		if (n == nullptr) {
			n = new Node();
			n->data = data;
			//see if rotations are needed
			checkBalance();
			return true;
		}

		//Decide where each node is placed recursively.
		if (n->data > data) {
			return insert(n->left, data);
		}
		else if (n->data < data) {
			return insert(n->right, data);
		}
		return false;

	}
	
	
	//insert post order from file in order that establishes original tree.
	void FileInsert(Node*& n, vector<string>& arr1, int size) {

		
		stack<Node*> postOrder;
		n = new Node();
		n->data = arr1[size - 1];

		postOrder.push(n);
		Node* current = nullptr;
		Node* temp = nullptr;
		Node* top = nullptr;

		
		

		for (int i = size - 2; i >= 0; i--) {
			
			current = new Node();
			if (i > 0) { temp = nullptr;}
			current->data = arr1[i];
		
			while (!(postOrder.empty())) {
				if (top == nullptr) {
					top = new Node();
					top->data = postOrder.top()->data;
				}
				else {
					top = postOrder.top();
					top->data = postOrder.top()->data;
				}
			
			
				if (current->data >= top->data) {
					break;
				}
				if (temp == nullptr) {
					temp = new Node();
					temp->data = top->data;
				}
				else {

					temp = top;
					temp->data = top->data;
					
				}
				postOrder.pop();

			}

			if (temp != nullptr) {
				temp->left = current;
				
			}
			else {
				
				top = postOrder.top();
				top->right = current;
			}

			postOrder.push(current);
		}
		checkBalance();
	}

	void PrintBalance(Node* n, ostream& os) {
		if (n->left != nullptr) {
			PrintBalance(n->left, os);
		}
		if (n->right != nullptr) {
			PrintBalance(n->right, os);
		}


		os << n->data << " has a bf of: " << n->bf << endl;
	}


	//Traverse tree and output in order, post order, and pre order.
	void InOrder(Node* n, ostream& os) {
		if (n == nullptr) {
			return;
		}
		if (n->left != nullptr) {
			InOrder(n->left, os);
		}
		os << n->data << ", ";
		if (n->right != nullptr) {
			InOrder(n->right, os);
		}
	}


	void PreOrder(Node* n, ostream& os) {
		os << n->data << endl;

		if (n->left != nullptr) {
			PreOrder(n->left, os);
		}
		if (n->right != nullptr) {
			PreOrder(n->right, os);
		}
	}

	void PostOrder(Node* n, ostream& os) {



		if (n->left != nullptr) {
			PostOrder(n->left, os);
		}
		if (n->right != nullptr) {
			PostOrder(n->right, os);
		}


		os << n->data << endl;
	}



	//Search for item in Tree and return true if it is in the Tree.
	bool Search(Node* n, string str) {
		if (n->data != str) {
			if (n->data > str && n->left != nullptr) {
				return Search(n->left, str);
			}
			else if (n->data < str && n->right != nullptr) {
				return Search(n->right, str);
			}
			return false;
		}
		else {
			return true;
		}
	}


	//Delete if string is in the tree, replace root by going left and all the way right.
	bool Del(Node*& n, string str) {


		if (n == nullptr) {
			return false;
		}

		if (n->data != str) {
			if (n->left != nullptr && n->data > str) {
				return Del(n->left, str);

			}

			else if (n->right != nullptr && n->data < str) {
				return Del(n->right, str);
			}
			else {
				return false;
			}
		}
		else {

			if (n->left == nullptr && n->right == nullptr) {
				delete n;
				n = nullptr;
				return true;
			}
			else if (n->left == nullptr) {
				Node* temp = n;
				n = n->right;
				delete temp;
				return true;
			}

			else if (n->right == nullptr) {
				Node* temp = n;
				n = n->left;
				delete temp;
				return true;
			}

			else {
				Node* temp = n->left;
				while (temp->right != nullptr) {
					temp = temp->right;
				}

				n->data = temp->data;
				return Del(n->left, n->data);
			}
		}
	}

	//Remove and set every node to NULL.
	void Clear(Node*& n) {
		if (n != nullptr) {
			if (n->left != nullptr) {
				Clear(n->left);
			}
			if (n->right != nullptr) {
				Clear(n->right);
			}


			n = nullptr;
		}
	}

	//Output post order to file of users choosing.
	void PostFileOrder(Node* n, ofstream& ofs) {



		if (n->left != nullptr) {
			PostOrder(n->left, ofs);
		}
		if (n->right != nullptr) {
			PostOrder(n->right, ofs);
		}


		ofs << n->data << endl;
	}






	//rotation when balance factor is negative and under -1
	Node* LL(Node*& n) {

		Node* temp = n;
		temp = temp->right;
		Node* temp2 = temp->left;
		temp->left = n;
		n->right = temp2;
		n = temp;
		

		return n;
	}

	//rotation when balance factor is positive over 1
	Node* RR(Node*& n) {

		Node* temp = n;
		temp = temp->left;
		Node* temp2 = temp->right;
		temp->right = n;
		n->left = temp2;
		n = temp;
		
		
		return n;
	}

	//find out what the balance factor is of a node
	Node* BalanceFactor(Node* n) {


		if (n != nullptr) {
			int leftHeight = Height(n->left);
			int rightHeight = Height(n->right);
			n->bf = leftHeight - rightHeight;
			if (n->bf > 1 || n->bf < -1) {
				Node* temp;
				Node* temp2;
				if (n->bf == 2) {
					temp = n->left;

					if (Height(temp->left) < Height(temp->right)) {
						temp2 = LL(temp);
						n->left = temp2;
						
					}

					n = RR(n);
					BalanceFactor(n->right);

					return n;
				}

				if (n->bf == -2) {
					temp = n->right;
					if (Height(temp->left) > Height(temp->right)) {
						temp2 = RR(temp);
						n->right = temp2;
						
					}

					n = LL(n);
					BalanceFactor(n->left);
					return n;
				}

			}
			return n;
		}
		else {
			return n;
		}

	}





	//I did not know how to handle a right and left height case, so i used sanfoundry.com.
	//This funnction recursively finds the height of each node and adds as it moves back up the tree.
	int Height(Node*& n) {
		int height = 0;


		if (n != nullptr) {

			int leftHeight = Height(n->left);
			int rightHeight = Height(n->right);

			int maxHeight = largest(leftHeight, rightHeight);
			height = maxHeight + 1;
		}

		return height;
	}

	void CheckBalance(Node*& n) {
		if (n->left != nullptr) {
			CheckBalance(n->left);
		}
		if (n->right != nullptr) {
			CheckBalance(n->right);
		}

		n = BalanceFactor(n);
	}



	//find which height is larger
	int largest(int left, int right) {
		if (left > right) {
			return left;
		}
		return right;
	}
};
