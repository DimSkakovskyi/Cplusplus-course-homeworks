#include<iostream>

using namespace std;

int main() {
	int Game[3][3];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			Game[i][j] = 0;
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << "[" << i << "][" << j << "] = " << Game[i][j] << endl;
		}
	}

	return 0;
}