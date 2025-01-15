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
int findLength(Node *head)
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
Node *insertAtTail(int val, Node *head, Node *tail)
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
Node *insertAtPosition(int value, int pos, Node *&head, Node *&tail)
{
    if (head == NULL && tail == NULL)
    {
        cout << "Error linked list is empty " << endl;
        return NULL;
    }
    int len = findLength(head);
    if (pos <= 0 || len + 1 < pos)
    {
        cout << "Error invalid position " << endl;
        return NULL;
    }
    if (pos == 1)
    {
        return insertAtHead(value, head, tail);
    }
    if (pos == len + 1)
    {
        return insertAtTail(value, head, tail);
    }
    Node *newNode = new Node(value);
    Node *temp = head;
    pos -= 2;
    while (pos)
    {
        temp = temp->next;
    }
    newNode->next = temp;
    temp->next = newNode;
    return head;
}
bool searchLL(int target, Node *head)
{
    Node *temp = head;

    while (temp)
    {
        if (temp->data)
            return true;
        temp = temp->next;
    }
    return false;
}
int searchPos(int target, Node *head)
{
    Node *temp = head;
    int pos = 0;
    while (temp)
    {
        if (temp->data)
            return ++pos;
        pos++;
        temp = temp->next;
    }
    return pos;
}
Node *deleteAtHead(Node *head, Node *tail)
{
    if (!head)
    {
        cout << "Nothing to delete" << endl;
        return NULL;
    }
    if (head == tail)
    {
        Node *cNode = head;
        head = NULL;
        tail = NULL;
        delete cNode;
        return head;
    }
    Node *cNode = head;
    head = cNode->next;
    delete cNode;
    return head;
}
Node *deleteAtEnd(Node *&head, Node *&tail)
{
    if (!head)
    {
        cout << "Nothing to delete" << endl;
        return NULL;
    }
    if (head == tail)
    {
        Node *cNode = head;
        head = NULL;
        tail = NULL;
        delete cNode;
        return head;
    }
    Node *currNode = head;

    while (currNode->next->next)
    {
        currNode = currNode->next;
    }
    Node *lastNode = currNode->next;
    delete lastNode;
    currNode->next = NULL;
    return head;
    // 1->2->3->4->NULL
}
Node *deleteAtPos(int pos, Node *head, Node *tail)
{
    if (!head)
    {
        cout << "Nothing to delete" << endl;
        return NULL;
    }
    if (head == tail)
    {
        Node *cNode = head;
        head = NULL;
        tail = NULL;
        delete cNode;
        return head;
    }
    Node *cNode = head;
    Node *prev = NULL;
    pos--;
    while (pos)
    {
        prev = cNode;
        cNode = cNode->next;
        pos--;
    }
    prev->next = cNode->next;
    cNode->next = NULL;
    delete cNode;
    return head;

    // 1->2->3->4->
}
int main()
{
    system("cls");
    Node *head = NULL;
    Node *tail = NULL;
    head = deleteAtHead(head, tail);
    head = insertAtHead(1, head, tail);
    head = insertAtHead(2, head, tail);
    head = insertAtHead(3, head, tail);
    printLL(head);
    head = deleteAtPos(2, head, tail);
    printLL(head);
    // head = deleteAtHead(head, tail);
    // printLL(head);
    // head = deleteAtEnd(head, tail);
    // printLL(head);
    return 0;
}