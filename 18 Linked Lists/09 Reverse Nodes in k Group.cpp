#include <iostream>
#include <cstdlib>
#include <unordered_map>
using namespace std;
class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int value)
    {
        this->val = value;
        this->next = NULL;
    }
};
void insertAtHead(int value, ListNode *&head, ListNode *&tail)
{
    if (head == NULL && tail == NULL)
    {
        ListNode *newNode = new ListNode(value);
        head = newNode;
        tail = newNode;
    }
    else
    {
        ListNode *newNode = new ListNode(value);
        newNode->next = head;
        head = newNode;
    }
}
void print(ListNode *head)
{
    ListNode *currentNode = head;
    while (currentNode != NULL)
    {
        cout << currentNode->val << "->";
        currentNode = currentNode->next;
    }
    cout << "NULL" << endl;
}

int getLength(ListNode *head)
{
    int c = 0;
    ListNode *temp = head;
    while (temp)
    {
        c++;
        temp = temp->next;
    }
    return c;
}
ListNode *reverserKgroup(ListNode *head, int k)
{
    if (head == NULL || head->next == NULL)
        return head;

    if (getLength(head) < k)
        return head;

    ListNode *prev = NULL;
    ListNode *curr = head;
    int pos = 0;
    while (pos < k)
    {
        ListNode *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        pos++
    }
    if (curr)
    {
        ListNode *newHead = reverserKgroup(curr, k);
        head->next = newHead;
    }
    return prev;
}
int main()
{
    system("cls");
    ListNode *head = NULL;
    ListNode *tail = NULL;
    insertAtHead(5, head, tail);
    insertAtHead(4, head, tail);
    insertAtHead(3, head, tail);
    insertAtHead(2, head, tail);
    insertAtHead(1, head, tail);
    print(head);

    head = reverserKgroup(head, 2);
    print(head);

    return 0;
}