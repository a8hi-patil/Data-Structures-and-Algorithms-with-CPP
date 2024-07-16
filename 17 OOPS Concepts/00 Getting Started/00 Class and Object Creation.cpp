#include <iostream>
#include <cstdlib>
using namespace std;

class Student
{
public:
    int id;
    int age;
    string name;
    int nos;

    // Default constructor
    Student()
    {
        cout << "Default Constructor called ! " << endl;
    }
    // Parameterised constructor
    Student(int id, int age, string name, int nos)
    {
        cout << "Parameterised Constructor called ! " << endl;
        this->name = name;
        this->age = age;
        this->id = id;
        this->nos = nos;
    }
    // Copy constructor

    Student(const Student &srcObject)
    {
        cout << "Copy Constructor called ! " << endl;
        this->name = srcObject.name;
        this->age = srcObject.age;
        this->id = srcObject.id;
        this->nos = srcObject.nos;
    }
    void study()
    {
        cout << this->name << " is studying !!" << endl;
    }
    void bunk()
    {
        cout << this->name << " is bunking " << endl;
    }
    // Destructor
    ~Student()
    {
        cout << "Destructor Called ! " << endl;
    }
};
int main()
{
    system("cls");
    // Creating default object
    Student s;
    s.name = "Abhi";
    cout << s.name << endl;
    s.study();
    s.bunk();
    // Creating parameterised object
    Student s1(1, 15, "Abhijit", 5);
    s1.study();
    s1.bunk();

    // Creating copy of object
    Student s3 = s1;
    s3.study();
    s3.bunk();
    return 0;
}