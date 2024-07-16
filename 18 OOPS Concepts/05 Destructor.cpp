#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
class Student
{
public:
    string name;
    int *cgpaPtr;

    Student(string name, int cgpa)
    {
        this->name = name;
        cgpaPtr = new int;
        *cgpaPtr = cgpa;
    }
    Student(Student &obj)
    {
        this->name = obj.name;
        cgpaPtr = new int;
        *cgpaPtr = *obj.cgpaPtr;
    }
    void getInfo()
    {
        cout << "Name is " << name << " CGPA is " << *cgpaPtr << endl;
    }
    ~Student()
    {
        cout << " Hi I am destructor !" << endl;
        delete cgpaPtr;
    }
};
using namespace std;
int main()
{
    system("cls");
    Student s1("Rahul", 8);
    Student s2(s1);
    s1.getInfo();
    *(s2.cgpaPtr) = 10;
    s1.getInfo();
    s2.getInfo();

    return 0;
}