#include <iostream>
#include "tempstack.h"
using namespace std;

int main() {
	//stack of integers
	
	Stack<int>* stackInt = new Stack<int>;
	stackInt->peek();
	stackInt->push(60);
	cout << *stackInt << endl;
	stackInt->push(372);
	cout << *stackInt << endl;
	stackInt->pop();
	cout << *stackInt << endl;
	stackInt->pop();
	stackInt->push(55);
	stackInt->push(193);
	stackInt->push(12383);
	cout << *stackInt << endl;
	stackInt->peek();
	cout << *stackInt << endl;



	//stack of double
	Stack<double> stackFlt;
	stackFlt.peek();
	stackFlt.pop();
	stackFlt.push(69.863);
	cout << stackFlt << endl;
	stackFlt.push(34.272);
	stackFlt.peek();
	stackFlt.pop();
	cout << stackFlt << endl;
	stackFlt.pop();
	stackFlt.push(86.765);
	stackFlt.push(96.1212);
	stackFlt.push(769.8768);
	cout << stackFlt << endl;


	//stack of strings
	Stack<string> stackStg;
	stackStg.peek();
	stackStg.pop();
	stackStg.push("tree");
	cout << stackStg << endl;
	stackStg.push("coding is fun");
	stackStg.peek();
	stackStg.pop();
	cout << stackStg << endl;
	stackStg.pop();
	stackStg.push("hello");
	stackStg.push("apple");
	stackStg.push("united states");
	cout << stackStg << endl;

}
