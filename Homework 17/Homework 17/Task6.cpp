#include <iostream>
#include <string>

using namespace std;

class Animal;

void setValue(Animal&, int);

class Animal
{
public:
	int GetWeight() const { return itsWeight; }
	int GetAge() const { return itsAge; }
	friend void setValue(Animal& theAnimal, int theWeight);

private:
	int itsWeight;
	int itsAge;
};

void setValue(Animal& theAnimal, int theWeight)
{
	theAnimal.itsWeight = theWeight;
}

int main()
{
	Animal peppy;
	setValue(peppy, 5);
	return 0;
}
