#include <iostream>
#include <cstdlib>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int val)
    {
        this->data = val;
        this->prev = NULL;
        this->next = NULL;
    }
};

void printDLL(Node *head)
{
    Node *temp = head;
    while ((temp))
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
void printDLLR(Node *tail)
{
    Node *temp = tail;
    while ((temp))
    {
        cout << temp->data << "->";
        temp = temp->prev;
    }
    cout << "NULL" << endl;
}

int getLength(Node *head)
{
    int c = 0;
    Node *temp = head;

    while (temp)
    {
        c++;
        temp = temp->next;
    }
    return c;
}

Node *insertAtHead(int val, Node *&head, Node *&tail)
{
    Node *newNodeToAdd = new Node(val);

    if (head == NULL && tail == NULL)
    {
        // DLL is empty
        head = newNodeToAdd;
        tail = newNodeToAdd;
        return head;
    }
    else
    {

        newNodeToAdd->next = head;
        head->prev = newNodeToAdd;
        head = newNodeToAdd;
        return head;
    }
}
Node *inserAtTail(int val, Node *&head, Node *&tail)
{
    Node *nodeToAdd = new Node(val);

    if (head == NULL && tail == NULL)
    {
        head = nodeToAdd;
        tail = nodeToAdd;
        return head;
    }
    else
    {

        nodeToAdd->prev = tail;
        tail->next = nodeToAdd;
        tail = nodeToAdd;
        return head;
    }
}

Node *insertAtPos(int val, int pos, Node *&head, Node *&tail)
{
    if (pos == 1 || (head == NULL && tail == NULL))
    {
        return insertAtHead(val, head, tail);
    }
    int len = getLength(head);

    if (pos == len + 1)
    {
        return inserAtTail(val, head, tail);
    }
    Node *travller = head;
    pos -= 1;

    while (pos)
    {
        travller = travller->next;
        pos--;
    }

    Node *newNodeToAdd = new Node(val);

    // 1->2->3
    travller->prev->next = newNodeToAdd;
    newNodeToAdd->prev = travller->prev;
    newNodeToAdd->next = travller;
    travller->prev = newNodeToAdd;
    return head;
}

bool search(int target, Node *head, Node *tail)
{
    Node *forwardTravller = head;
    Node *reverserTravller = tail;

    while (forwardTravller || reverserTravller)
    {
        if (forwardTravller->data == target || reverserTravller->data == target)
            return true;
        forwardTravller = forwardTravller->next;
        reverserTravller = reverserTravller->prev;
    }
    return false;
}
Node *deleteFromPos(int pos, Node *&head, Node *&tail)
{
    if (head == NULL && tail == NULL)
        return NULL;

    if (head == tail)
    {
        delete head;
        return NULL;
    }
    if (pos == 1)
    {
        Node *cNode = head;
        head = cNode->next;
        cNode->prev = NULL;
        cNode->next = NULL;
        head->prev = NULL;
        delete cNode;
        return head;
    }
    if (pos == getLength(head))
    {
        Node *cNode = tail;
        tail = cNode->prev;
        tail->next = NULL;
        cNode->prev = NULL;
        delete cNode;
        return head;
    }

    Node *cNode = head;
    pos--;
    while (pos)
    {
        cNode = cNode->next;
        pos--;
    }

    cNode->prev->next = cNode->next;
    cNode->next->prev = cNode->prev;
    cNode->next = NULL;
    cNode->prev = NULL;
    delete cNode;
    return head;
}
int main()
{
    system("cls");
    Node *head = NULL;
    Node *tail = NULL;

    head = insertAtHead(7, head, tail);
    head = insertAtHead(8, head, tail);
    head = insertAtHead(9, head, tail);

    head = inserAtTail(6, head, tail);
    head = inserAtTail(5, head, tail);
    head = inserAtTail(4, head, tail);
    printDLL(head);
    printDLLR(tail);

    head = insertAtPos(99, 6, head, tail);

    printDLL(head);
    printDLLR(tail);
    // cout << search(6, head, tail) << endl;
    // cout << search(66, head, tail) << endl;

    cout << "Delete at End " << endl;
    head = deleteFromPos(7, head, tail);
    printDLL(head);
    printDLLR(tail);
    cout << "Delete at start " << endl;
    head = deleteFromPos(1, head, tail);
    printDLL(head);
    printDLLR(tail);
    cout << "Delete at mid " << endl;
    head = deleteFromPos(3, head, tail);
    printDLL(head);
    printDLLR(tail);

    return 0;
}