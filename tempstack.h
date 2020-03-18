#pragma once
/*
Adam Kuhnel
vak58
MWF 3:30 - 5
This program creates a stack using templates */

#pragma once
#include <iostream>

#define tempstack_H_
using namespace std;
using std::ostream;





template <typename T>
class Node
{
public:
	T data;
	Node<T>* next;
	Node() {
		next = NULL;
	}
	Node(T data, Node <T>* next = NULL) {
		this->data = data;
		this->next = next;

	}
};

template <typename T>
class Stack {
private:
	Node <T>* top;
	Node <T>* bottom;
public:
	Stack()
	{
		top = NULL;
		bottom = NULL;
	}



	void push(T data) {
		Node<T>* temp = new Node<T>;
		temp->data = data;
		temp->next = NULL;

		if (isEmpty()) {
			top = temp;
			bottom = temp;

		}
		else {
			top->next = temp;
			top = top->next;

		}
	}


	
	void pop() {
		if (bottom != NULL) {
			Node<T>* curr = new Node <T>;
			Node<T>* prev = new Node <T>;
			curr = bottom;
			if (curr->next == NULL) {
				bottom = NULL;
				top = NULL;
				return;
			}

			while (curr->next != NULL) {
				prev = curr;
				curr = curr->next;
			}


			top = prev;
			prev->next = NULL;
			delete curr;
		}
		else {
			cout << "This stack is already empty" << endl;
		}
	}


	void peek() {
		Node<T>* L = new Node<T>;
		L = top;
		if (isEmpty()) {
			cout << "this stack is empty" << endl;
		}
		else {
			cout << "This stack is not empty" << endl;
		}
	}
	
	friend ostream& operator<<(ostream& os, const Stack<T>& stack)
	{
		Node<T>* L = stack.bottom;
		os << "Bottom: ";
		for (L; L != 0; L = L->next) {
			os << L->data << ", ";
		}
		os << " Top" << endl;
		return os;

	}
	bool isEmpty() {
		if (top == NULL) {
			return true;
		}
		else {
			return false;
		}
	}

};


