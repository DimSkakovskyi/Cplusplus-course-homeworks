#include<iostream>
#include<string>

using namespace std;

//1,2

class Vehicle {
public:
	Vehicle(string& Model) : model(Model) {}
	virtual ~Vehicle() {}
	virtual void honk() = 0;
	virtual void drive() = 0;

private:
	string model;
};

class Car : public Vehicle {
public:
	Car(string& Model) : Vehicle(Model) {}
	virtual ~Car() {}
	virtual void drive() { cout << "You are driving" << endl; }
};

class SportsCar : public Car {
public:
	SportsCar(string& Model) : Car(Model) {}
	virtual ~SportsCar() {}
	virtual void honk() { cout << "SportsCar honk: Beep Beep!" << endl; }
	virtual void drive() { Car::drive(); cout << "In a sport car." << endl; }
};

class Wagon : public Car {
public:
	Wagon(string& Model) : Car(Model) {}
	virtual ~Wagon() {}
	virtual void honk() { cout << "Wagon honk: Beep Beep!" << endl; }
	virtual void drive() { Car::drive(); cout << "In a wagon." << endl; }
};

class Coupe : public Car {
public:
	Coupe(string& Model) : Car(Model) {}
	virtual ~Coupe() {}
	virtual void honk() { cout << "Coupe honk: Beep Beep!" << endl; }
	virtual void drive() { Car::drive(); cout << "In a Coupe." << endl; }
};

class Bus : public Vehicle {
public:
	Bus(string& Model) : Vehicle(Model) {}
	virtual ~Bus() {}
	virtual void honk() { cout << "Bus honk: Beep Beep!" << endl; }
	virtual void drive() { cout << "You are driving a bus." << endl; }
};

//3

class Engine {
public:
	Engine(const string& type) : type(type) { engineCount++; }
	~Engine() { engineCount--; }
	static int getEngineCount() {
		return engineCount;
	}
	void displayInfo() const {
		cout << "Engine type: " << type << endl;
	}

private:
	string type;
	static int engineCount;
};

int Engine::engineCount = 0;

int main() {
	Engine engine1("V8");
	Engine engine2("Electric");
	Engine engine3("Hybrid");

	engine1.displayInfo();
	engine2.displayInfo();
	engine3.displayInfo();

	std::cout << "Total engines: " << Engine::getEngineCount() << std::endl;

	return 0;
}