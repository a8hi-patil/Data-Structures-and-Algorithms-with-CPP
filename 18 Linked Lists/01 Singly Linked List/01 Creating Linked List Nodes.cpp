#include <iostream>
#include <cstdlib>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
};
int main()
{
    system("cls");

    Node *newNode = new Node(10); // Dynamic memory Allocation
    Node newNode1(20);            // Static memory allocation
    return 0;
}