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
Node *insertAtHead(int value, Node *&head, Node *&tail)
{
    // If there is no node prensent in linked list
    // Created new node and return head
    if (head == NULL && tail == NULL)
    {
        // creating new node
        Node *newNode = new Node(value);
        // After creating node assign head and tail to it
        head = newNode;
        tail = newNode;
    }
    else
    {
        // If there are node present in the linked list
        // Create new node assign
        // Connect new node next to head then assign head to new node
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }
    return head;
}
Node *insertAtEnd(int value, Node *&head, Node *&tail)
{
    // if there is no node present in linked list
    // create a node and assign head and tail to same
    if (head == NULL && tail == NULL)
    {
        // creating a new node
        Node *newNode = new Node(value);
        head = newNode;
        tail = newNode;
    }
    else
    {
        // if there are nodes present in linked list
        // create a new node and attach it to tail.
        // assign last node to tail
        Node *newNode = new Node(value);
        tail->next = newNode;
        tail = newNode;
    }
    return head;
};
void printLinkedList(Node *head)
{
    while (head != NULL)
    {
        Node *currentNode = head;
        cout << currentNode->data << "->";
        head = currentNode->next;
    }
    cout << "NULL" << endl;
}
int findLength(Node *&head)
{
    int count = 0;

    Node *currNode = head;
    while (currNode != NULL)
    {
        count++;
        currNode = currNode->next;
    }
    return count;
}
Node *insertAtPosition(int pos, Node *head, Node *tail, int value)
{
    if (pos <= 0)
    {
        cout << "Erro : negative index" << endl;
        return NULL;
    }
    if (pos == 1)
    {
        return insertAtHead(value, head, tail);
    }
    int len = findLength(head);
    if (pos == len + 1)
    {
        return insertAtEnd(value, head, tail);
    }
    if (pos > len)
    {
        cout << "Erro : invalid index" << endl;
        return NULL;
    }

    Node *curNode = head;
    for (int i = 0; i < pos - 2; i++)
    {
        curNode = curNode->next;
        pos--;
    }
    Node *newNode = new Node(value);
    newNode->next = curNode->next;
    curNode->next = newNode;
    return head;
}

bool search(int target, Node *head)
{
    int pos = 1;
    Node *curNode = head;
    while (curNode != NULL)
    {
        if (curNode->data == target)
        {
            cout << "Target found at position " << pos << endl;
            return true;
        }
        else
        {
            curNode = curNode->next;
        }
        pos++;
    }
    return false;
}
int main()
{
    system("cls");
    Node *head = NULL;
    Node *tail = NULL;
    head = insertAtHead(5, head, tail);
    printLinkedList(head);
    head = insertAtHead(15, head, tail);
    printLinkedList(head);
    head = insertAtHead(25, head, tail);
    head = insertAtPosition(2, head, tail, 99);
    printLinkedList(head);
    cout << "Length is " << findLength(head) << endl;
    cout << search(15, head) << endl;
    cout << search(89, head) << endl;
    ;
    Node *head1 = NULL;
    Node *tail1 = NULL;
    head1 = insertAtEnd(5, head1, tail1);
    printLinkedList(head1);
    head1 = insertAtEnd(15, head1, tail1);
    printLinkedList(head1);
    head1 = insertAtEnd(25, head1, tail1);
    printLinkedList(head1);
    head1 = insertAtEnd(35, head1, tail1);
    printLinkedList(head1);
    return 0;
}