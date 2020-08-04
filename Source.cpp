/*
Adam Kuhnel
vak58
MWF 3:30 - 5
This program creates a bst using nodes */

#include <iostream>
#include "BST.h"
using namespace std;
#include <fstream>
#include<cstdlib>
#include<vector>
using std::ofstream;


int main() {

	//Create instance of bst and strings to store user inputs.
	Tree Binary;
	cout << endl;
	string operation;
	string strInput;
	string fileName;
	string newBstCheck;


	//Loop through the users options until the user types exit. 
	string z = "y";
	while (z == "y") {
		//Display the users options and collect input using the console.
		cout << "what operation would you like to perform (ins, search, newAVL, checkBF, del, pre, post, in, postFile, existingFile, exit): ";
		cin >> operation;
		cout << endl;

		//Match the users input with the member function they want to use.
		if (operation == "ins") {
			string insertString;
			while (insertString != "Done") {
				cout << "Type Done when all insertions are made. Enter the string you would like to insert: ";
				cin >> insertString;
				cout << endl;
				if (insertString != "Done") {
					Binary.Insert(insertString);

				}
			}
		}
		else if (operation == "search") {
			cout << "Enter the string you would like to search for: ";
			cin >> strInput;
			cout << endl;
			if (Binary.search(strInput)) {
				cout << "This is in the BST " << endl;
			}
			else {
				cout << "This string was not found" << endl;
			}
		}
		else if (operation == "checkBF") {
			Binary.printBalance(cout);
			cout << endl;
		}
		else if (operation == "newAVL") {
			cout << "are you sure, this will delete your previous AVL(y/n): ";
			cin >> newBstCheck;
			if (newBstCheck == "y") {
				Binary.clear();
			}

		}
		else if (operation == "del") {
			cout << "Enter the string you would like to delete: ";
			cin >> strInput;
			cout << endl;
			Binary.del(strInput);
		}
		else if (operation == "pre") {
			cout << endl;
			Binary.preOrder(cout);
			cout << endl;
		}
		else if (operation == "post") {
			Binary.postOrder(cout);
			cout << endl;
		}
		else if (operation == "in") {
			Binary.inOrder(cout);
			cout << endl;
		}
		else if (operation == "postFile") {
			cout << "Enter the name of your file: ";
			cin >> fileName;
			cout << endl;
			ofstream ofs(fileName);

			Binary.postfileorder(ofs);


		}

		else if (operation == "existingFile") {
			//get filename from user and store it
			char fileName[50];
			cout << "Enter the name of your file: ";
			cin >> fileName;

			cout << endl;
			int Iterator = 0;

			vector<string> tree;

			
			ifstream fileToArr;
			fileToArr.open(fileName);

			fileToArr >> fileName;
			// find the nuber of nodes in the tree
			if (fileToArr.is_open()) {
				while (fileToArr.good()) {

					//create a vector of each element in the tree
					tree.push_back(fileName);
					fileToArr >> fileName;
					
										
					Iterator++;

				}

				
			}
			else {
				exit;
			}
			fileToArr.close();
			//clear current tree
			Binary.clear();
			vector<string>& arr1 = tree;
			//insert back as tree
			Binary.fileInsert(arr1, Iterator);
			Binary.printBalance(cout);
		}
	
		
		//Set the z condition to no when user types exit.
		else if (operation == "exit") {
			z = "n";
		}
		else {
			cout << "ERROR: Please enter a valid input" << endl;
		}



	}
}






