#include<iostream>

using namespace std;

int Exponentiation(int base, int power);

//class Employee tasks
class Employee {
private:
	unsigned short int age;
	unsigned short int yearsOfService;
	unsigned int Salary;

public:
	Employee(unsigned short int newAge, unsigned short int newYearsOfService, unsigned int newSalary) {
		age = newAge;
		yearsOfService = newYearsOfService;
		Salary = newSalary;
	}

	unsigned short int GetAge() {
		return age;
	}
    
	void SetAge(unsigned short int newAge) {
		age = newAge;
	}

	unsigned short int GetYearsOfService() {
		return yearsOfService;
	}

	void SetYearsOfService(unsigned short int newYearsOfService) {
		yearsOfService = newYearsOfService;
	}

	unsigned short int GetSalary() {
		return Salary;
	}

	void SetSalary(unsigned short int newSalary) {
		Salary = newSalary;
	}

	void Show() {
		cout << "\nAge: " << age;
		cout << "\nYears of service: " << yearsOfService;
		cout << "\nSalary: " << Salary;
	}

	void ShowSalary() {
		int shownSalary = Salary / 10;
		shownSalary *= 10;
		cout << "\nSalary: " << shownSalary;
	}
};

int main() {
	//1
	int firstNum, secondNum, result;
	cout << "Enter first number: ";
	cin >> firstNum;
	cout << "\nEnter first number: ";
	cin >> secondNum;
	result = Exponentiation(firstNum, secondNum);
	cout << "Result of exponentiation: " << result << endl;

	Employee Peter(34, 10, 20000);
	Employee David(25, 3, 10000);
	
	cout << "\nInformation about Peter: ";
	Peter.Show();

	cout << "\nInformation about David: ";
	David.Show();

	Employee James(30, 2, 556);
	James.ShowSalary();

	return 0;
}


int Exponentiation(int base, int power) {
	if (power == 0) {
		return 1;
	}
	else {
		return base * Exponentiation(base, power-1);
	}
}