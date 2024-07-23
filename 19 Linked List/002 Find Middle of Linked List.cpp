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
Node *findMiddle(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
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
    Node *middleNode = findMiddle(head);
    cout << ":: Finding Middle of Linked List ::" << endl;
    cout << "Middled Node is " << middleNode->data << endl;
    head = insertAtHead(50, head, tail);
    printLL(head);
    middleNode = findMiddle(head);
    cout << ":: Finding Middle of Linked List ::" << endl;
    cout << "Middled Node is " << middleNode->data << endl;

    printLL(head);
    return 0;
}