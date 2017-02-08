/*
Homework 1 - EndSert Method
Jackson Tran
This program consists of code already provided, but with an added method.
The program will use methods in a class to create a list. 
1063 Data Structures
Spring 2017
2/6/2017
*/



#include <iostream>

struct Node {
	int Data;
	Node *Next;
};

using namespace std;

class List {
private:
	Node *Head;
	Node *Tail;
public:
	List() {
		Head = NULL;
		Tail = NULL;
	}

	void FrontSert(int x) {
		Node *Temp = new Node;
		Temp->Data = x;
		Temp->Next = NULL;

		if (Head) {
			Temp->Next = Head;
		}
		Head = Temp;
		if (!Tail) {
			Tail = Head;
		}
		
	}

	/*
	Function name:EndSert
	Will use the Tail pointer to link nodes to the end of the list
	Parameters:
	integer x - will determine what goes into the node
	Returns: void
	*/

	void EndSert(int x) {
		Node *Temp = new Node;
		Temp->Data = x;
		Temp->Next = NULL;

		if (Tail != NULL){
			if (Temp->Next == NULL) {
				Tail->Next = Temp;
				Tail = Tail->Next;
			}
		}
		else {
			Head = Temp;
		}

	}
	

		

	void PrintList() {
		if (!Head) {
			cout << "Empty" << endl;
			return;
		}
		else {
			Node *Temp = Head;
			while (Temp != NULL) {
				cout << Temp->Data << "->";
				Temp = Temp->Next;
			}
		}
		
	}

};


int main() {
	List L;
	L.EndSert(92);
	L.PrintList();
	cout << endl;

	L.FrontSert(83);
	L.PrintList();
	cout << endl;

	L.FrontSert(54);
	L.PrintList();
	cout << endl;

	L.FrontSert(43);
	L.PrintList();
	cout << endl;

	L.FrontSert(34);
	L.PrintList();
	cout << endl;

	L.EndSert(21);
	L.PrintList();
	cout << endl;

	L.EndSert(70);
	L.PrintList();
	cout << endl;

	L.FrontSert(42);
	L.PrintList();
	cout << endl;
	system("pause");
	return 0;
}
