#include <iostream>
#include <cstdlib>
using namespace std;
class Node
{
public:
    int *next;
    int *prev;
    int val;
    int *child;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->child = NULL;
        this->prev = NULL;
    }
};
Node *solve(Node *head)
{

    Node *temp = head;
    Node *prev;
    while (temp != NULL)
    {
        if (temp->child != NULL)
        {
            Node *nextNode = temp->next; // 4
            Node *childNode = temp->child;
            temp->next = childNode;
            childNode->prev = temp;
            Node *newTail = solve(temp->child);
            newTail->next = nextNode;
            if (nextNode != NULL)
                nextNode->prev = newTail;
            temp->child = NULL;
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }
    }
    return prev;
}

class Solution
{
public:
    Node *flatten(Node *head)
    {
        solve(head);

        return head;
    }
};
int main()
{
    system("cls");
    return 0;
}