#include <iostream>

using namespace std;

class Cats {
private:
    int age; 
    static int count; 
    string name;
    string breed;
    string color;

public:
    Cats(int years, string catName, string catBreed, string catColor)
        : age(years), name(catName), breed(catBreed), color(catColor) {
        count++;
        cout << "Object created. Count: " << count << endl;
    }

    ~Cats() {
        count--;
        cout << "Object destroyed. Count: " << count << endl;
    }

    void show() const {
        cout << "Age: " << age << ", Count: " << count << endl;
    }

    static int getCount() {
        return count;
    }

    int getAge() {
        return age;
    }

    string getName() const {
        return name;
    }

    string getBreed() const {
        return breed;
    }

    string getColor() const {
        return color;
    }
};

int Cats::count = 0;

int main() {
    Cats* Frisky = new Cats(10, "Frisky", "Siamese", "White");
    Cats* Daisy = new Cats(12, "Daisy", "Persian", "Gray");
    Cats* Luna = new Cats(8, "Luna", "Maine Coon", "Black");

    int (Cats:: * pGetAge)() = &Cats::getAge;

    string (Cats:: * pName)() const = &Cats::getName;
    string(Cats:: * pBreed)() const = &Cats::getBreed;
    string(Cats:: * pColor)() const = &Cats::getColor;

    Frisky->show();
    Daisy->show();
    Luna->show();

    cout << endl;

    cout << "Frisky's age is: " << (Frisky->*pGetAge)() << endl;
    cout << "Daisy's age is: " << (Daisy->*pGetAge)() << endl;
    cout << "Luna's age is: " << (Luna->*pGetAge)() << endl;

    cout << endl;

    cout << "Frisky's color is: " << (Frisky->*pColor)() << endl;
    cout << "Daisy's breed is: " << (Daisy->*pBreed)() << endl;
    cout << "Luna's name is: " << (Luna->*pName)() << endl;

    cout << endl;

    delete Frisky;
    delete Daisy;
    delete Luna;
    
    return 0;
}
