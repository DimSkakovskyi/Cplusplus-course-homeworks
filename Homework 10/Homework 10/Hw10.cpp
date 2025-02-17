#include<iostream>

using namespace std;

class Shape {
public:
	Shape() {};
	~Shape() {};
};

class Rectangle : public Shape {
public:
	Rectangle() : length(1), width(2) {}
	Rectangle(int width, int length) : length(length), width(width) {}
	~Rectangle() {}

private:
	int length, width;
};

class Square : public Rectangle {
public:
	Square() : length(1) {}
	Square(int length);
	~Square() {}

private:
	int length;
};

Square::Square(int length) : Rectangle(length, length) {
}

class SimpleCircle {
public:
	SimpleCircle();
	SimpleCircle(int val);
	SimpleCircle(const SimpleCircle& rhs);
	~SimpleCircle();

	int GetRadius() const { return *itsRadius;  }
	void SetRadius(int x) { *itsRadius = x; }

	const SimpleCircle& operator++();
	const SimpleCircle operator++(int);
	const SimpleCircle& operator=(const SimpleCircle& rhs);

private:
	int* itsRadius;
};

SimpleCircle::SimpleCircle()
{
	itsRadius = new int(0);
	cout << "SimpleCircle constructor...\n";
}

SimpleCircle::SimpleCircle(int val)
{
	itsRadius = new int(val);
	cout << "SimpleCircle constructor...\n";
}

SimpleCircle::SimpleCircle(const SimpleCircle& rhs)
{
	itsRadius = new int(rhs.GetRadius());
	cout << "SimpleCircle copy constructor...\n";
}

SimpleCircle::~SimpleCircle()
{
	delete itsRadius;
	cout << "SimpleCircle destructor...\n";
}

const SimpleCircle& SimpleCircle::operator++() {
	++(*itsRadius);
	return *this;
}

const SimpleCircle SimpleCircle::operator++(int) {
	SimpleCircle temp = *this;
	++(*itsRadius);
	return temp;
}

const SimpleCircle& SimpleCircle::operator=(const SimpleCircle& rhs) {
	itsRadius = new int(rhs.GetRadius());
	return *this;
}

int main() {
	SimpleCircle Circle1;
	SimpleCircle Circle2(9);

	cout << "Circle1 radius " << Circle1.GetRadius() << endl;
	cout << "Circle2 radius " << Circle2.GetRadius() << endl;
	cout << endl;

	Circle1++;
	Circle2++;

	cout << "Circle1 radius " << Circle1.GetRadius() << endl;
	cout << "Circle2 radius " << Circle2.GetRadius() << endl;
	cout << endl;

	Circle1 = Circle2;

	cout << "Circle1 radius " << Circle1.GetRadius() << endl;
	cout << "Circle2 radius " << Circle2.GetRadius() << endl;

	return 0;
}