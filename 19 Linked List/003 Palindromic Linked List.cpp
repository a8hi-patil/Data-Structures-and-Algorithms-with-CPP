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

Node *findMid(Node *head, Node *&prevToMid)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            prevToMid = slow;
            slow = slow->next;
        }
    }
    return slow;
}

Node *reverseLL(Node *head)
{
    Node *prevNode = NULL;
    Node *currentNode = head;
    while (currentNode != NULL)
    {
        Node *nextNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    return prevNode;
}
bool isLLPalidromic(Node *head)
{
    // single element it node
    if (head->next == NULL)
    {
        return true;
    }
    // empty lis

    if (head == NULL)
    {
        return true;
    }

    // find mid and previous to mid
    Node *prevToMid = NULL;
    Node *mid = findMid(head, prevToMid);

    // break at mid and reverse the second half
    prevToMid->next = NULL;
    Node *reversedLLHead = reverseLL(mid);
    // compare
    Node *firstHalfHead = head;
    Node *secondHalfhead = reversedLLHead;
    while (firstHalfHead != NULL)
    {
        if (firstHalfHead->data != secondHalfhead->data)
        {
            return false;
        }
        else
        {
            firstHalfHead = firstHalfHead->next;
            secondHalfhead = secondHalfhead->next;
        }
    }
    return true;
}
int main()
{
    system("cls");
    Node *head = NULL;
    Node *tail = NULL;
    head = insertAtHead(10, head, tail);
    head = insertAtHead(20, head, tail);
    head = insertAtHead(20, head, tail);
    head = insertAtHead(10, head, tail);
    printLL(head);
    cout << isLLPalidromic(head) << endl;

    return 0;
}