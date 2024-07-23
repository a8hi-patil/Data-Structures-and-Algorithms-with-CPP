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

Node *insertAtHead(int value, Node *head, Node *tail)
{
    if (head == NULL && tail == NULL)
    {
        Node *newNode = new Node(value);
        head = newNode;
        tail = newNode;
    }
    else
    {
        Node *nodeToBeInserted = new Node(value);
        nodeToBeInserted->next = head;
        head = nodeToBeInserted;
    }
    return head;
}

Node *reverseLL(Node *prevNode, Node *currentNode)
{
    if (currentNode == NULL)
    {
        return prevNode;
    }
    Node *nextNode = currentNode->next;
    currentNode->next = prevNode;
    prevNode = currentNode;
    currentNode = nextNode;
    return reverseLL(prevNode, currentNode);
}
void printLL(Node *head)
{
    Node *currentNode = head;
    while (currentNode != NULL)
    {
        cout << currentNode->data << "->";
        currentNode = currentNode->next;
    }
    cout << "NULL" << endl;
}
int main()
{
    system("cls");
    Node *head = NULL;
    Node *tail = NULL;
    head = insertAtHead(10, head, tail);
    head = insertAtHead(20, head, tail);
    head = insertAtHead(30, head, tail);
    head = insertAtHead(40, head, tail);
    printLL(head);
    cout << ":: Reversing Linked List ::" << endl;
    Node *prevNode = NULL;
    Node *currentNode = head;
    head = reverseLL(prevNode, currentNode);
    printLL(head);
    return 0;
}