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
        this->next = NULL;
        this->prev = NULL;
    }
};
void printDLL(Node *head)
{
    Node *currNode = head;
    while (currNode != NULL)
    {
        cout << currNode->data << "->";
        currNode = currNode->next;
    }
    cout << "NULL" << endl;
}
void printDLLR(Node *tail)
{
    Node *currNode = tail;
    while (currNode != NULL)
    {
        cout << currNode->data << "->";
        currNode = currNode->prev;
    }
    cout << "NULL" << endl;
}
int getLength(Node *head)
{
    int len = 0;
    Node *currNode = head;
    while (currNode != NULL)
    {
        len++;
        currNode = currNode->next;
    }
    return len;
}
void insertAtHead(int value, Node *&head, Node *&tail)
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
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
}
void insertAtEnd(int value, Node *&head, Node *&tail)
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
        newNode->prev = tail;
        tail = newNode;
    }
}
void insertAtPos(int value, int pos, Node *&head, Node *&tail)
{
    if (head == NULL && tail == NULL)
    {
        return insertAtHead(value, head, tail);
    }
    if (pos == 1)
    {
        return insertAtHead(value, head, tail);
    }
    if (pos == getLength(head) + 1)
    {
        return insertAtEnd(value, head, tail);
    }
    Node *currNode = head;
    for (int i = 0; i < pos - 2; i++)
        currNode = currNode->next;

    Node *newNode = new Node(value);
    Node *forwardNode = currNode->next;
    newNode->prev = currNode;
    newNode->next = forwardNode;
    currNode->next = newNode;
    forwardNode->prev = newNode;
}
bool search(int target, Node *head)
{
    Node *currNode = head;
    while (currNode != NULL)
    {
        if (currNode->data == target)
        {
            return false;
        }
    }
    return false;
}

void deleteFromPos(int pos, Node *&head, Node *tail)
{
    if (head == NULL && tail == NULL)
    {
        cout << "No node to delete " << endl;
        return;
    }
    else if (head == tail)
    {
        Node *currNode = head;
        currNode->prev = NULL;
        currNode->next = NULL;
        delete currNode;
        return;
    }
    else if (getLength(head) == pos)
    {
        Node *nodeToBeDeleted = tail;
        tail = nodeToBeDeleted->prev;
        tail->next = NULL;
        nodeToBeDeleted->prev = NULL;
        return;
    }
    else if (pos == 1)
    {
        Node *currNode = head;
        head = head->next;
        currNode->next = NULL;
        currNode->prev = NULL;
        delete currNode;
    }
    else
    {
        Node *prevNode = head;
        for (int i = 0; i < pos - 2; i++)
            prevNode = prevNode->next;

        Node *nodeToBeDeleted = prevNode->next;
        Node *forwardNode = nodeToBeDeleted->next;

        prevNode->next = forwardNode;
        forwardNode->prev = prevNode;
        nodeToBeDeleted->next = NULL;
        nodeToBeDeleted->prev = NULL;
        delete nodeToBeDeleted;
    }
}

int main()

{
    system("cls");
    Node *head = NULL;
    Node *tail = NULL;
    insertAtHead(20, head, tail);
    insertAtHead(40, head, tail);
    printDLL(head);
    insertAtEnd(80, head, tail);
    printDLL(head);
    insertAtPos(800, 2, head, tail);
    printDLL(head);
    insertAtPos(803, 4, head, tail);
    printDLL(head);
    cout << "del3" << endl;
    deleteFromPos(3, head, tail);
    printDLL(head);
    cout << "del1" << endl;
    deleteFromPos(1, head, tail);
    printDLL(head);
    cout << "del3" << endl;
    deleteFromPos(3, head, tail);
    printDLL(head);
    // cout << getLength(head);
    // printDLLR(tail);
    return 0;
}