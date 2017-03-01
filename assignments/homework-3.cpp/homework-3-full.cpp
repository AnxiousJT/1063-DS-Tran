/*
 @Homework: Homework-3
 @Author: Jackson Tran
 @Description:The majority of this code was created during class, but the
 print method didn't work properly when called to print a full array. The
 homework assignment is to fix the print method to work with any content
 in the array
 @Course: 1063 Data Structures
 @Semester: Spring 2017
 @Date: 02-28-2017
*/
#include <iostream>
#include <random>

using namespace std;

class ArrQueue {
private:
	int ArraySize;
	int *Q;
	int Front;
	int Rear;
	int NumItems;
public:
	ArrQueue(int size = 10) {
		ArraySize = size;
		Q = new int[ArraySize];
		Front = Rear = NumItems = 0;
	}

	bool Push(int value) {
		if (Full()) {
			cout << "Queue Full!" << endl;
			return false;
		}
		Q[Rear] = value;
		Rear = (Rear + 1) % ArraySize;
		NumItems++;
		return true;
	}

	int Pop() {
		if (Empty()) {
			cout << "Queue Empty!" << endl;
			return false;
		}
		int Temp = Q[Front];
		Front = (Front + 1) % ArraySize;
		NumItems--;
		return Temp;
	}

	bool Empty() {
		return (NumItems == 0);
	}

	bool Full() {
		return (NumItems == ArraySize);
	}

	void PrintFR() {
		cout << "Front: " << Front << "Rear: " << Rear << endl;
	}
/*
 @FunctionName: Print
 @Description: To allow print to work with the full array
 when called, I used an or statement with a variable that I would change
 so that the method would work without going through an infinite loop
 @Params: None
 @Returns: None
 */
	void Print() {
		int Index = Front;
		int fullCheck = 0;
		while (Index != Rear || fullCheck == 0) {
			cout << Q[Index] << " ";
			Index = ((Index + 1) % (ArraySize));
			fullCheck++;
		}
		cout << endl;
	}
};

int main() {
	srand(983475);
	ArrQueue Q;
	int r = 0;
	bool result;

	for (int i = 0; i < 10; i++) {
		r = rand() % 100;
		result = Q.Push(r);
		if (result)
			cout << r << endl;
	}
	Q.PrintFR();
	Q.Print();
	cout << Q.Pop() << endl;
	cout << Q.Pop() << endl;
	cout << Q.Pop() << endl;
	cout << Q.Pop() << endl;
	cout << Q.Pop() << endl;

	Q.Print();
	cout << Q.Pop() << endl;
	cout << Q.Pop() << endl;
	cout << Q.Pop() << endl;
	for (int i = 0; i < 3; i++) {
		r = rand() % 100;
		result = Q.Push(r);
		if (result)
			cout << r << endl;
	}
	Q.Print();
	system("pause");
	return 0;
}
