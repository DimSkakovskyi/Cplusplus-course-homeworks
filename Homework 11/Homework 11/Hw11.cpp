#include<iostream>

using namespace std;

class Point {
public:
	Point() : x(0), y(0) { cout << "Point constructor...\n"; }
	Point(int x, int y) : x(x), y(y) { cout << "Point constructor...\n"; }
	Point(const Point& rhs);
	~Point() {}

	int GetX() const { return x; }
	int GetY() const { return y; }

private:
	int x, y;
};

Point::Point(const Point& rhs) : x(rhs.GetX()), y(rhs.GetY())
{
}

class Rectangle {
public:
	Rectangle() : topLeft(0, 1), topRight(2, 1), bottomLeft(0, 0), bottomRight(2, 0) { cout << "Rectangle constructor...\n"; }
	virtual ~Rectangle() { cout << "Rectangle destructor...\n"; }
	Rectangle(const Rectangle& rhs);

	virtual Rectangle *Clone() { return new Rectangle(*this); }

protected:
	Point topLeft, topRight, bottomLeft, bottomRight;
};

Rectangle::Rectangle(const Rectangle& rhs) : topLeft(rhs.topLeft), topRight(rhs.topRight), bottomLeft(rhs.bottomLeft), bottomRight(rhs.bottomRight)
{
	cout << "Rectangle copy constructor...\n";
}

class Square : public Rectangle {
public:
	Square() { cout << "Square constructor...\n"; }
	virtual ~Square() { cout << "Sqaure destructor...\n"; }
	Square(const Square& rhs);

	virtual Rectangle* Clone() { return new Square(*this); }
};

Square::Square(const Square& rhs) : Rectangle(rhs)
{
	cout << "Square copy constructor...\n";
}

int main() {

	return 0;
}