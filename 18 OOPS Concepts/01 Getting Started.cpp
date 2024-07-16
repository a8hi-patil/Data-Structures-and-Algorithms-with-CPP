#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
class Teacher
{
protected:
    int yoe;

private:
    int salary;

public:
    string name;
    string dept;
    string subject;

    // data member
    void sayName()
    {
        cout << "Name is " << name << endl;
    }
    // getter
    string getName()
    {
        return name;
    }
    // setter
    void setName(string newName)
    {
        name = newName;
    }
};
int main()
{
    system("cls");
    Teacher t1;
    // Accessible cause data and data members are  public.
    t1.name = " Abhijit";
    t1.subject = "CPP";
    t1.dept = "IT";
    t1.sayName();
    string fetchedName = t1.getName();
    t1.sayName();
    t1.setName("Aayush");

    // Inaccessible cause data and data members are private and protected
    //  t1.salary = 5000;
    //  t1.yoe = 4;

    return 0;
}