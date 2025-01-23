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
void print(Node *head)
{
    Node *it = head;
    while (it)
    {
        cout << it->data << " ";
        it = it->next;
    }
    cout << "NULL" << endl;
}
int getLength(Node *head)
{
    int c = 0;
    Node *it = head;
    while (it)
    {
        c++;

        it = it->next;
    }
    return c;
}
Node *insertAtHead(int val, Node *head, Node *tail)
{
    Node *newNode = new Node(val);
    if (head == NULL && tail == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
    return head;
}
Node *rotate(Node *head, int k)
{
    if (!head)
        return head;
    int len = getLength(head);
    if (k > len)
    {
        k = k % len;
    }
    if (k == 0)
        return head;

    Node *it = head;
    Node *newHead = NULL;
    for (int i = 0; i < len - k - 1; i++)
    {
        it = it->next;
    }
    newHead = it->next;
    it->next = NULL;
    it = newHead;
    while (it->next)
    {
        it = it->next;
    }
    it->next = head;
    return newHead;
}
int main()
{
    system("cls");
    Node *head = NULL;
    Node *tail = NULL;
    head = insertAtHead(5, head, tail);
    head = insertAtHead(4, head, tail);
    head = insertAtHead(3, head, tail);
    head = insertAtHead(2, head, tail);
    head = insertAtHead(1, head, tail);
    print(head);
    head = rotate(head, 3);
    print(head);
    return 0;
}