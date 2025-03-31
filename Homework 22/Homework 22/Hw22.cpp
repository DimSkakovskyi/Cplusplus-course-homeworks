#include <iostream>
using namespace std;

class xValue
{
public:
    xValue(int value) : itsValue(value) {}
    virtual ~xValue() {}
    virtual void PrintError() const = 0;

protected:
    int itsValue;
};

class xTooSmall : public xValue
{
public:
    xTooSmall(int value) : xValue(value) {}
    void PrintError() const override
    {
        cout << "Error: Value too small! (" << itsValue << ")" << endl;
    }
};

class xTooBig : public xValue
{
public:
    xTooBig(int value) : xValue(value) {}
    void PrintError() const override
    {
        cout << "Error: Value too big! (" << itsValue << ")" << endl;
    }
};

//Level 2

int GetInput()
{
    int number;
    cout << "Enter a number between 10 and 100: ";
    cin >> number;
    return number;
}

//Level3

void ValidateValue(int number)
{
    if (number < 10)
        throw xTooSmall(number);
    else if (number > 100)
        throw xTooBig(number);
}

//Level1

void ProcessValue()
{
    int value = GetInput();     
    ValidateValue(value);        
    cout << "Value is acceptable: " << value << endl;
}

int main()
{
    try
    {
        ProcessValue();
    }
    catch (xValue& e)
    {
        e.PrintError();
    }

    return 0;
}
