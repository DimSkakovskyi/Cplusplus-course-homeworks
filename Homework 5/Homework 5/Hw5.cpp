#include<iostream>

using namespace std;

//1 task
unsigned long int Perimeter(unsigned long int, unsigned long int);
short int Division(unsigned short int, unsigned short int);

int main() {
	//6 task
	unsigned short int a , b;
	cout << "Enter first number: ";
	cin >> a;
	cout << "Enter second number: ";
	cin >> b;

	short int result = Division(a, b);
	if (result == -1) {
		cout << "\nError: Dividing by zero!" << endl;
	}
	else {
		cout << "\nFirst  number: " << a << "\nSecond number: " << b;
		cout << "\nResult: " << result << endl;
	}
}

//2 task
unsigned long int Perimeter(unsigned long int length, unsigned long int width) {
	return (2 * length + 2 * width);
}

//5 task
short int Division(unsigned short int firstNum, unsigned short int secondNum) {
	if (secondNum == 0) {
		return -1;
	}
	return (firstNum / secondNum);
}