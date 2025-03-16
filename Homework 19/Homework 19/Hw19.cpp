#include <iostream>
#include <fstream>

using namespace std;

bool isPrintableChar(char ch) {
    return (ch >= 32 && ch <= 126) || ch == '\t' || ch == '\n' || ch == ' ';
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Enter arguments for the program" << endl;
        return 1;
    }

    cout << "Reversed command-line arguments:" << endl;
    for (int i = argc - 1; i > 0; i--) {
        cout << argv[i] << " ";
    }
    cout << endl;

    ifstream inputFile(argv[1]);

    if (!inputFile) {
        cerr << "Error: Cannot open file " << argv[1] << endl;
        return 1;
    }

    char ch;
    while (inputFile.get(ch)) { 
        if (isPrintableChar(ch)) {
            cout << ch;
        }
    }

    inputFile.close(); 
    return 0;
}
