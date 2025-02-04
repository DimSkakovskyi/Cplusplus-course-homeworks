#include<iostream>

using namespace std;

//9
class Cat
{
public:
	Cat(int age) { itsAge = age; }
	~Cat() {}
	int GetAge() const { return itsAge; }

private:
	int itsAge;
};

int main() {
	//1
	int number = 10;
	int* pNum = &number;
	int& ref = number;

	cout << "Number: " << number << endl << endl;

	*pNum = 20;

	cout << "Number: " << number << endl << endl;

	ref = 30;

	cout << "Number: " << number << endl << endl;

	
	//2, 3
	
	/*int varOne = 6;
	const int *const pNumber = &varOne; 
	*pNumber = 7;
	int varTwo = 8;
	pNumber = &varTwo;*/


	//4
	//Despite the fact that I tried similar code to the example from the lesson
	//VS didn't give a permission to access *pNumber after delete and thrown an error
	
	/*int* pNumber = new int;
	*pNumber = 50;
	cout << "Number1 is: " << *pNumber << endl;
    delete pNumber;

	float *pFloat = new float;
	*pFloat = 25.5;
	cout << "Number2 is: " << *pFloat << endl;

	*pNumber = 15;
	
	cout << "Number1 is: " << *pNumber << endl;
	cout << "Number2 is: " << *pNumber << endl;*/

	//5
	int* pNumber = new int;
	*pNumber = 50;
	cout << "Number1 is: " << *pNumber << endl;
	delete pNumber;
	pNumber = nullptr;

	float* pFloat = new float;
	*pFloat = 25.5;
	cout << "Number2 is: " << *pFloat << endl;

	//6

	/*int* ptr = new int;
	*ptr = 5;
	cout << "We have number: " << *ptr << endl;*/

	//7
	int* ptr = new int;
	*ptr = 5;
	cout << "We have number: " << *ptr << endl;
	delete ptr;

	//9
	int age = 7;
	Cat* Boots = MakeCat(age);
	cout << "Boots is: " << Boots->GetAge() << " years old" << endl;
	delete Boots;

	return 0;
}

Cat* MakeCat(int age)
{
	Cat* pCat = new Cat(age);
	return pCat;
}