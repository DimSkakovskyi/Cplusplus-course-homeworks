#include <iostream>
#include <string>

using namespace std;

int main() {
    string name;
    int age;

    //task2
    char entierName[256];
    cout << "Enter your entier name: ";
    cin.getline(entierName, 256);

    cout << "\nEntierName: " << entierName << endl;

    //task1
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

    //task3
    char ch;
    cout << "enter a phrase: ";
    while (cin.get(ch))
    {
        if (ch == '!')
            cout << '$';
        else if (ch == '#')
            continue;
        else
            cout << ch;
    }

    return 0;
}

//enter a phrase : Now!is#the!time#for!fun#!
//Now$isthe$timefor$fun$
