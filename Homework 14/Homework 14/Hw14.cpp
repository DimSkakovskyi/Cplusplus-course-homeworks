#include<iostream>

using namespace std;

class Rocket {
public:
	Rocket() { cout << "Rocket constructor..." << endl; }
	virtual void Launch() { cout << "Launching rocket!" << endl; }
	virtual ~Rocket() { cout << "Rocket destructor..." << endl; }
};

class Airplane {
public:
	Airplane() { cout << "Airplane constructor..." << endl; }
	virtual void Fly() { cout << "Flying airplane!" << endl; }
	virtual ~Airplane() { cout << "Airplane destructor..." << endl; }
};

class JetPlane : public Rocket, public Airplane {
public:
	JetPlane() { cout << "JetPlane constructor..." << endl; }
	~JetPlane() { cout << "JetPlane destructor..." << endl; }
	virtual void JetPlaneFly() { cout << "Flying JetPlane!" << endl; }
};

class Boeing747 : public JetPlane {
public:
	Boeing747() { cout << "Boeing747 constructor..." << endl; }
	~Boeing747() { cout << "Boeing747 destructor..." << endl; }
	virtual void FlyBoeing() { cout << "Boeing747 si flying!" << endl; }
};

int main() {
	JetPlane jp;
	jp.Launch();       
	jp.Fly();            
	jp.JetPlaneFly();

	cout << endl;
	Boeing747 Boeing;
	Boeing.Launch();        
	Boeing.Fly();           
	Boeing.JetPlaneFly();
	Boeing.FlyBoeing();
	cout << endl;


	return 0;
}