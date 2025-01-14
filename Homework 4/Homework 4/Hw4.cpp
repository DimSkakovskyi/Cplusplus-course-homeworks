#include<iostream>

using namespace std;

int main() {
	//1
	int x = 5;
	int y = 3;
	cout << "Before\n";
	cout << "x: " << x << "\ny: " << y << endl;
	cout << endl;

	if (x > y) {
		x = y;
	}
	else {
		y = x;
	}

	cout << "After\n";
	cout << "x: " << x << "\ny: " << y << endl;

	return 0;
}