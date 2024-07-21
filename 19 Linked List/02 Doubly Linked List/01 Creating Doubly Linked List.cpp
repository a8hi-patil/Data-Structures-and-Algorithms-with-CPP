#include <iostream>
#include <cstdlib>
using namespace std;
class Node
{
public:
    Node *prev;
    int data;
    Node *next;
    Node(int value)
    {
        this->data = value;
        this->prev = NULL;
        this->next = NULL;
    }
};
int main()
{
    system("cls");
    Node *n1 = new Node(16);
    return 0;
}