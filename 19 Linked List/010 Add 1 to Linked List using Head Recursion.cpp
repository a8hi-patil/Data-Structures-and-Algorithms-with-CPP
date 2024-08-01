#include <iostream>
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

void insertAtHead(Node *&head, Node *&tail, int val)
{
    if (head == NULL || tail == NULL)
    {
        Node *newNode = new Node(val);
        head = newNode;
        tail = newNode;
    }
    else
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void solve(Node *&head, int &carry)
{
    if (head == NULL)
        return;

    solve(head->next, carry);
    int sum = head->data + carry;
    int digit = sum % 10;
    head->data = digit;
    carry = sum / 10;
}

void add1(Node *&head)
{
    int carry = 1;
    solve(head, carry);
    if (carry)
    {
        Node *newNode = new Node(carry);
        newNode->next = head;
        head = newNode;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertAtHead(head, tail, 9);
    insertAtHead(head, tail, 9);
    insertAtHead(head, tail, 9);
    insertAtHead(head, tail, 9);
    insertAtHead(head, tail, 9);
    add1(head);
    print(head);
    return 0;
}