#include<iostream>

using namespace std;

class intData {
public:
	intData(int val) : myValue(val) {}
	~intData() {}
	void Show() { cout << myValue << endl; }

private:
	int myValue;
};

class Node {
public:
	Node(intData *theData) : myData(theData), next(nullptr) {}
	~Node() {
		delete myData;
		delete next;
	}

	void Show() {
		myData->Show();
	}

private:
	intData* myData;
	Node* next;
};

int main() {

	return 0;
}