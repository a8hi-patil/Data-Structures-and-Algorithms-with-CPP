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
void printLL(Node *head)
{
    Node *currNode = head;
    while (currNode != NULL)
    {
        cout << currNode->data << "->";
        currNode = currNode->next;
    }
    cout << "NULL" << endl;
}
int findlength(Node *head)
{
    int len = 0;
    Node *tempNode = head;
    while (tempNode != NULL)
    {
        len++;
        tempNode = tempNode->next;
    }
    return len;
}
Node *insertAtHead(int value, Node *&head, Node *&tail)
{
    if (head == NULL && tail == NULL)
    {
        Node *newNode = new Node(value);
        head = newNode;
        tail = newNode;
    }
    else
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }
    return head;
}
Node *insertAtTail(int value, Node *&head, Node *&tail)
{

    if (head == NULL && tail == NULL)
    {
        Node *newNode = new Node(value);
        head = newNode;
        tail = newNode;
    }
    else
    {
        Node *newNode = new Node(value);
        tail->next = newNode;
        tail = newNode;
    }
    return head;
}
Node *insertAtPosition(int value, int pos, Node *head, Node *tail)
{
    if (head == NULL && tail == NULL)
    {
        cout << "Error linked list is empty " << endl;
        return NULL;
    }
    int len = findlength(head);
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
    Node *currNode = head;
    for (int i = 1; i < pos - 1; i++)
    {
        currNode = currNode->next;
    }
    Node *newNode = new Node(value);
    newNode->next = currNode->next;
    currNode->next = newNode;
    return head;
}
bool searchLL(int target, Node *head)
{
    if (head == NULL)
    {
        return false;
    }
    Node *currNode = head;
    while (currNode != NULL)
    {
        if (currNode->data == target)
        {
            return true;
        }
        currNode = currNode->next;
    }
    return false;
}
int searchPos(int target, Node *head)
{
    int pos = 0;
    if (head == NULL)
    {
        return -1;
    }
    Node *currNode = head;
    while (currNode != NULL)
    {
        if (currNode->data == target)
        {
            return ++pos;
        }
        currNode = currNode->next;
        pos++;
    }
    return -1;
}

Node *deleteAtHead(Node *&head, Node *&tail)
{
    if (head == NULL && tail == NULL)
    {
        cout << "No node to delete" << endl;
        return NULL;
    }
    if (head == tail)
    {
        Node *temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        return NULL;
    }
    Node *currNode = head;
    head = currNode->next;
    currNode->next = NULL;
    delete currNode;
    return head;
}
void deleteAtEnd(Node *&head, Node *&tail)
{
    if (head == NULL && tail == NULL)
    {
        cout << "No node to delete" << endl;
        return;
    }
    if (head == tail)
    {
        Node *temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        return;
    }
    Node *currNode = head;
    while (currNode->next->next != NULL)
    {
        currNode = currNode->next;
    }
    delete currNode->next->next;
    currNode->next = NULL;
    tail = currNode;
}
void deleteAtPos(int pos, Node *&head, Node *&tail)
{
    if (head == NULL && tail == NULL)
    {
        cout << "No node to delete" << endl;
        return;
    }
    if (head == tail)
    {
        Node *temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        return;
    }

    if (pos == 1)
    {
        Node *firstNode = head;
        head = firstNode->next;
        firstNode->next = NULL;
        delete firstNode;
        return;
    }
    Node *currNode = head;
    for (int i = 0; i < pos - 2; i++)
    {
        currNode = currNode->next;
    }
    Node *nextNode = currNode->next;
    currNode->next = nextNode->next;
    delete nextNode;
}
int main()
{
    system("cls");
    Node *head = NULL;
    Node *tail = NULL;

    head = insertAtHead(10, head, tail);
    head = insertAtHead(20, head, tail);
    head = insertAtHead(30, head, tail);
    printLL(head);
    head = insertAtTail(40, head, tail);
    head = insertAtTail(50, head, tail);
    head = insertAtTail(60, head, tail);
    printLL(head);
    head = insertAtPosition(100, 1, head, tail);
    printLL(head);
    head = insertAtPosition(1000, 8, head, tail);
    printLL(head);
    head = insertAtPosition(1, 5, head, tail);
    printLL(head);
    cout << searchLL(50, head) << " " << searchPos(50, head) << endl;
    cout << searchLL(89, head) << " " << searchPos(89, head) << endl;
    head = deleteAtHead(head, tail);
    printLL(head);
    deleteAtEnd(head, tail);
    printLL(head);
    deleteAtPos(3, head, tail);
    printLL(head);
    deleteAtPos(1, head, tail);
    printLL(head);
    return 0;
}