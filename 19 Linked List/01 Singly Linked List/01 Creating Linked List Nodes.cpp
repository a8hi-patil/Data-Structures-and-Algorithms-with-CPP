#include <iostream>
#include <cstdlib>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        this->data = value;
        this->next = NULL;
    }
};

int main()
{
    system("cls");

    Node *node1 = new Node(10);
    Node node2(20);
    return 0;
}