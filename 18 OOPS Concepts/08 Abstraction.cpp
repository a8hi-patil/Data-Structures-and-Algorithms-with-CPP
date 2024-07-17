#include <iostream>
#include <cstdlib>
using namespace std;
// Abstract class
class Shape
{
    virtual void draw() = 0; // Pure virtual function
    // If pure virtual funtion lies in class that class automatically becomes abstract class
};

class Circle : public Shape
{

public:
    void draw()
    {

        cout << "Drawing a circle " << endl;
    }
};
int main()
{
    system("cls");
    // Shape s1; //Object of abstract class type "Shape" is not allowed:
    Circle c1;
    c1.draw();
    return 0;
}