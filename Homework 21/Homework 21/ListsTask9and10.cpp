#include <iostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

class Student
{
public:
    Student();
    Student(const string& name, const int age);
    Student(const Student& rhs);
    ~Student();

    void SetName(const string& name);
    string GetName() const;
    void SetAge(const int age);
    int GetAge() const;
    Student& operator=(const Student& rhs);

private:
    string itsName;
    int itsAge;
};

class StudentPrinter
{
public:
    void operator()(const Student& s) const
    {
        cout << s << endl;
    }
};

Student::Student() : itsName("New Student"), itsAge(16) {}
Student::Student(const string& name, const int age) : itsName(name), itsAge(age) {}
Student::Student(const Student& rhs) : itsName(rhs.GetName()), itsAge(rhs.GetAge()) {}
Student::~Student() {}

void Student::SetName(const string& name) { itsName = name; }
string Student::GetName() const { return itsName; }
void Student::SetAge(const int age) { itsAge = age; }
int Student::GetAge() const { return itsAge; }

Student& Student::operator=(const Student& rhs)
{
    itsName = rhs.GetName();
    itsAge = rhs.GetAge();
    return *this;
}

ostream& operator<<(ostream& os, const Student& rhs)
{
    os << rhs.GetName() << " is " << rhs.GetAge() << " years old";
    return os;
}

typedef list<Student> SchoolClass;

template <class T>
void ShowList(const list<T>& lst)
{
    cout << "size() = " << lst.size();
    cout << "\t " << (lst.empty() ? "empty" : "not empty") << endl;

    for_each(lst.begin(), lst.end(), StudentPrinter());

    cout << endl;
}

int main()
{
    Student Harry("Harry", 18);
    Student Sally("Sally", 15);
    Student Bill("Bill", 17);
    Student Peter("Peter", 16);

    SchoolClass myClass;

    myClass.push_back(Harry);
    myClass.push_back(Sally);
    myClass.push_back(Bill);
    myClass.push_back(Peter);

    cout << "SchoolClass after push_back:\n";
    ShowList(myClass);

    for (auto& student : myClass)
    {
        int currentAge = student.GetAge();
        student.SetAge(currentAge + 1);
    }

    cout << "SchoolClass after aging everyone by 1 year:\n";
    ShowList(myClass);

    return 0;
}
