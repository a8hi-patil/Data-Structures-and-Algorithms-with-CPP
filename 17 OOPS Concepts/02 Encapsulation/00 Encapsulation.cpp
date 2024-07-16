#include <iostream>
#include <cstdlib>
using namespace std;
class WithoutEncapsulation
{
public:
    int id;
    string name;
    int rollNo;
    string gfName;

    // Default Constructor
    WithoutEncapsulation()
    {
        cout << "Default constructor called" << endl;
    }
    // Parameterised Constructor
    WithoutEncapsulation(int id, string name, int rollNo, string gfName)
    {
        cout << "Parameterised constructor called" << endl;
        this->id = id;
        this->name = name;
        this->rollNo = rollNo;
        this->gfName = gfName;
    }
    // Copy Contructor
    WithoutEncapsulation(const WithoutEncapsulation &srcObj)
    {
        cout << "Copy constructor called" << endl;
        this->id = srcObj.id;
        this->name = srcObj.name;
        this->rollNo = srcObj.rollNo;
        this->gfName = srcObj.gfName;
    }
    // Defining some public methods
    void studyin()
    {
        cout << this->name << " is studying !" << endl;
    }
    void chatting()
    {
        cout << this->name << " is chatting with his GF " << this->gfName << endl;
    }
    // Destructor
    ~WithoutEncapsulation()
    {
        cout << "Destructor is called" << endl;
    }
};
class WithEncapsulation
{
private:
    int id;
    string name;
    int rollNo;
    string gfName;

public:
    // Default Constructor
    WithEncapsulation()
    {
        cout << "Default constructor called" << endl;
    }
    // Parameterised Constructor
    WithEncapsulation(int id, string name, int rollNo, string gfName)
    {
        cout << "Parameterised constructor called" << endl;
        this->id = id;
        this->name = name;
        this->rollNo = rollNo;
        this->gfName = gfName;
    }
    // Copy Contructor
    WithEncapsulation(const WithoutEncapsulation &srcObj)
    {
        cout << "Copy constructor called" << endl;
        this->id = srcObj.id;
        this->name = srcObj.name;
        this->rollNo = srcObj.rollNo;
        this->gfName = srcObj.gfName;
    }

    string getName()
    {
        return this->name;
    }
    void setName(string name)
    {
        this->gfName = name;
        chatting();
    }

private:
    // Defining some public methods
    void studyin()
    {
        cout << this->name << " is studying !" << endl;
    }
    void chatting()
    {
        cout << this->name << " is chatting with his GF " << this->gfName << endl;
    }

public:
    // Destructor
    ~WithEncapsulation()
    {
        cout << "Destructor is called" << endl;
    }
};
int main()
{
    system("cls");
    WithoutEncapsulation s1;
    // Here we can able to access any method and data object.
    s1.id = 1;
    s1.name = "S1";
    s1.rollNo = 1;
    s1.gfName = "GFS1";
    cout << "Detais" << s1.id << " " << s1.name << " " << s1.rollNo << " " << s1.gfName << endl;
    s1.studyin();
    s1.chatting();
    WithEncapsulation s2(2, "S2", 2, "GFS2");
    // Data is in accessible
    // cout << "Detais" << s2.id << " " << s2.name << " " << s2.rollNo << " " << s2.gfName << endl;
    // s2.chatting();
    // s2.studyin();
    cout << s2.getName() << endl;
    cout << "Setting name " << endl;
    s2.setName("aish");
    cout << s2.getName() << endl;
    return 0;
}