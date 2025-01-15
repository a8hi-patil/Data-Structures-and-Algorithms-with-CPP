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

Node *insertAtHead(int val, Node *&head, Node *&tail)
{
    // Create New Node
    Node *newNode = new Node(val);
    if (head == NULL && tail == NULL)
    {
        // LL is empty
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
Node *insertAtTail(int val, Node *&head, Node *&tail)
{
    Node *newNode = new Node(val);
    if (head == NULL && tail == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
    return head;
}
void printLL(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int findLenght(Node *head)
{
    Node *temp = head;
    int counter = 0;
    while (temp)
    {
        counter++;
        temp = temp->next;
    }
    return counter;
}
Node *insertAtPos(int val, int pos, Node *&head, Node *&tail)
{
    if (pos < 0)
    {
        cout << "Error :: Position not exists";
        return head;
    }
    int len = findLenght(head);
    if (pos > len + 1)
    {

        cout << "Error :: Position not exists";
        return head;
    }
    if (pos == 1)
    {
        return insertAtHead(val, head, tail);
    }
    if (pos == len)
    {
        return insertAtTail(val, head, tail);
    }
    Node *newNode = new Node(val);
    Node *temp = head;
    pos--;
    pos--;
    while (pos)
    {
        temp = temp->next;
        pos--;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}
bool search(Node *head, int target)
{
    Node *temp = head;
    while (temp)
    {

        if (temp->data == target)
            return true;
        temp = temp->next;
    }
    return false;
}
int main()
{
    system("cls");
    Node *head = NULL;
    Node *tail = NULL;

    head = insertAtHead(10, head, tail);
    printLL(head);
    head = insertAtHead(20, head, tail);
    printLL(head);
    head = insertAtHead(30, head, tail);
    printLL(head);
    head = insertAtTail(5, head, tail);
    head = insertAtTail(4, head, tail);
    head = insertAtTail(3, head, tail);
    printLL(head);
    cout << findLenght(head) << endl;
    head = insertAtPos(33, 2, head, tail);
    printLL(head);
    cout << search(head, 3) << endl;
    cout << search(head, 30) << endl;
    cout << search(head, 10) << endl;
    cout << search(head, 366) << endl;

    return 0;
}