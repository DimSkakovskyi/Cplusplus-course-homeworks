#include<iostream>

using namespace std;

int main() {
	//2
	int myArray[10][10];

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			myArray[i][j] = 0;
		}
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << myArray[i][j];
		}
		cout << endl;
	}

	//3
	for (int i = 100; i < 200; i += 2) {
	}

	//4
	int counter = 100;
	while (counter < 200) {
		counter += 2;
	}

	//5
	int counter2 = 100;
	do {
		counter += 2;
	} while (counter < 200);

	return 0;
}