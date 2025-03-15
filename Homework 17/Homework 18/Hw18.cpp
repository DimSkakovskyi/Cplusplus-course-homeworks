#include <iostream>
#include <string>

using namespace std;

int main() {
    string name;
    int age;

    cout << "Enter your name: ";
    cin >> name;

    cout << "Enter your age: ";
    cin >> age;

    cout << "Hello, " << name << "! You are " << age << " years old." << endl;

    if (age < 0) {
        cerr << "Error: Age cannot be negative!" << endl;
    }

    clog << "User entered name: " << name << " and age: " << age << endl;

    cout << endl;

    char entierName[256];
    cout << "Enter your entier name: ";
    cin.getline(entierName, 256);

    cout << "entierName: " << entierName << endl;

    return 0;
}
