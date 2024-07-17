#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Person
{
public:
    string name;
    int age;

    // Person()
    // {
    //     cout << "Parent Constructor" << endl;
    // }
    Person(string name, int age)
    {
        cout << "Parent Constructor" << endl;
        this->name = name;
        this->age = age;
    }
    ~Person()
    {
        cout << "Parent Destructor" << endl;
    }
};

class Student : public Person
{
public:
    int rollNo;

    Student(string name, int age, int rollNo) : Person(name, age)
    {
        cout << "Child Constructor " << endl;
        this->rollNo = rollNo;
    }
    void getInfo()
    {
        cout << "Name " << name << " age " << age << " roll no. " << rollNo << endl;
    }
    ~Student()
    {
        cout << "Child Destructor " << endl;
    }
};
int main()
{
    system("cls");
    // Student s1;
    // s1.name = "A";
    // s1.age = 16;
    // s1.rollNo = 21;
    // s1.getInfo();
    Student s1("Rahul Kumar", 16, 32);
    s1.getInfo();
    return 0;
}