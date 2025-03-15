#include <iostream>
#include <string>

using namespace std;

//task1,2,3
class Animal {
public:
    Animal(const string& animalName);
    ~Animal();
    string getName() const;
    void show() const;

private:
    string name;
};

Animal::Animal(const string& animalName) : name(animalName) {
    cout << "Animal created: " << name << endl;
}

Animal::~Animal() {
    cout << "Animal destroyed: " << name << endl;
}

string Animal::getName() const {
    return name;
}

void Animal::show() const {
    cout << "Animal Name: " << name << endl;
}

class BoundedArray {
public:
    BoundedArray(int s);
    ~BoundedArray();
    void set(int index, int value);
    int get(int index) const;
    int getSize() const;
    void display() const;

private:
    int* arr;
    int size;
};

BoundedArray::BoundedArray(int s) : size(s) {
    if (size <= 0) {
        throw invalid_argument("Size must be positive.");
    }
    arr = new int[size];
    for (int i = 0; i < size; ++i) {
        arr[i] = 0;
    }
}

BoundedArray::~BoundedArray() {
    delete[] arr;
}

void BoundedArray::set(int index, int value) {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of bounds.");
    }
    arr[index] = value;
}

int BoundedArray::get(int index) const {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of bounds.");
    }
    return arr[index];
}

int BoundedArray::getSize() const {
    return size;
}

void BoundedArray::display() const {
    cout << "BoundedArray: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

class Set {
private:
    BoundedArray elements;
    int currentSize;

public:
    Set(int capacity) : elements(capacity), currentSize(0) {}

    void insert(int value) {
        for (int i = 0; i < currentSize; ++i) {
            if (elements.get(i) == value) {
                return; 
            }
        }
        if (currentSize < elements.getSize()) {
            elements.set(currentSize, value);
            currentSize++;
        }
        else {
            cout << "Set is full!" << endl;
        }
    }

    void display() const {
        cout << "Set: ";
        for (int i = 0; i < currentSize; ++i) {
            cout << elements.get(i) << " ";
        }
        cout << endl;
    }
};

int main() {
   
    Animal* dog = new Animal("Buddy");
    Animal* cat = new Animal("Whiskers");

    cout << endl;

    dog->show();
    cat->show();

    cout << endl;

    delete dog;
    delete cat;

    cout << endl;

    BoundedArray myArray(5);
    myArray.set(0, 10);
    myArray.set(1, 20);
    myArray.set(2, 30);
    myArray.set(3, 40);
    myArray.set(4, 50);

    myArray.display();

    cout << "Value at index 2: " << myArray.get(2) << endl;

    cout << endl;

    Set mySet(5);
    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(10);
    mySet.insert(30);
    mySet.insert(40);
    mySet.insert(50);
    mySet.insert(60);
    mySet.display();
    

    return 0;
}
