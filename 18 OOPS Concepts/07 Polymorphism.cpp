#include <iostream>
#include <cstdlib>
using namespace std;
// Compile time - Method Overloading
class Student
{
public:
    string name;
    // Funtion Overloading
    Student()
    {
        cout << "Non-Parameterized contructor" << endl;
    }
    Student(string name)
    {
        cout << "Parameterized contructor" << endl;
        this->name = name;
    }
};
// Compile time - Method Overloading
class Print
{
public:
    // Funtion Overloading
    void show(int x)
    {
        cout << "int " << x << endl;
    }
    void show(char x)
    {
        cout << "char " << x << endl;
    }
};

// Compile time - Operator Overloading
class ComplexNumber
{
private:
    int real;
    int img;

public:
    ComplexNumber()
    {
        cout << "Created" << endl;
    }
    ComplexNumber(int real, int img)
    {
        this->img = img;
        this->real = real;
    }

    void printComplexNumber()
    {
        cout << real << " +" << " i" << img << endl;
    }

    ComplexNumber operator+(ComplexNumber const &srcObj)
    {
        ComplexNumber res;
        res.real = this->real + srcObj.real;
        res.img = this->img + srcObj.img;
        return res;
    }
};

// Run time polymorphism - Function Overriding
class Parent
{
public:
    void getInfo()
    {
        cout << "I am parent class" << endl;
    }
    virtual void hello()
    {
        cout << "hello from parent class" << endl;
    }
};
class Child : public Parent
{
public:
    void getInfo()
    {
        cout << "I am child class" << endl;
    }
    void hello()
    {
        cout << "hello from child class" << endl;
    }
};
int main()
{
    system("cls");
    Print p;
    p.show(8);
    p.show('a');
    ComplexNumber c1(12, 9);
    ComplexNumber c2(10, 8);
    ComplexNumber c3 = c1 + c2;
    c3.printComplexNumber();
    Parent p1;
    Child ch1;
    p1.getInfo();
    ch1.getInfo();
    ch1.hello();
    p1.hello();

    return 0;
}