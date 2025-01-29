#include<iostream>

using namespace std;

int main() {
	//3
	int number = 20;
	int *pNumber = &number;
	cout << "Before: " << number << endl;
	*pNumber = 50;
	cout << "After: " << number << endl;

	//4
	int myVariable;
	int* pMyVariable = &myVariable;
	*pMyVariable = 70;
	cout << "My variable: " << myVariable << endl;

	return 0;
}