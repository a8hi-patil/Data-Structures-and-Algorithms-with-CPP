#include <iostream>
#include <cstdlib>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;

    ListNode(int val)
    {
        this->data = val;
        this->next = NULL;
    }
};

void printL(ListNode *head)
{
    ListNode *travller = head;
    while (travller)
    {
        cout << travller->data << "->";
        travller = travller->next;
    }
    cout << "NULL" << endl;
}
ListNode *insertAtHead(int val, ListNode *&head, ListNode *&tail)
{
    ListNode *newNode = new ListNode(val);

    if (head == NULL && tail == NULL)
    {
        head = newNode;
        tail = newNode;
        return head;
    }
    else
    {
        newNode->next = head;
        head = newNode;
        return head;
    }
}
ListNode *rev(ListNode *&head)
{
    ListNode *prev = NULL;
    ListNode *curr = head;
    while (curr)
    {
        ListNode *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}
ListNode *solve(ListNode *prev, ListNode *curr)
{
    if (curr == NULL)
    {
        return prev;
    }
    ListNode *nextNode = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nextNode;
    return solve(prev, curr);
}
int main()
{
    system("cls");
    ListNode *head = NULL;
    ListNode *tail = NULL;
    head = insertAtHead(5, head, tail);
    head = insertAtHead(4, head, tail);
    head = insertAtHead(3, head, tail);
    head = insertAtHead(2, head, tail);
    head = insertAtHead(1, head, tail);
    printL(head);
    head = rev(head);
    printL(head);
    ListNode *prev = NULL;
    head = solve(prev, head);
    printL(head);
    return 0;
}