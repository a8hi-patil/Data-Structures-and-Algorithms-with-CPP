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

ListNode *removeDuplicateNode(ListNode *head, ListNode *tail)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    ListNode *unique = head;
    ListNode *curr = head;

    while (curr)
    {
        if (curr->val == unique->val)
        {
            curr = curr->next;
        }
        else
        {
            unique->next = curr;
            unique = curr;
            curr = curr->next;
        }
    }
    unique->next = NULL;
    return head;
}
int main()
{
    system("cls");
    ListNode *head = NULL;
    ListNode *tail = NULL;
    insertAtHead(10, head, tail);
    insertAtHead(10, head, tail);
    insertAtHead(20, head, tail);
    insertAtHead(30, head, tail);
    insertAtHead(30, head, tail);

    print(head);
    head = removeDuplicateNode(head, tail);
    print(head);

    return 0;
}