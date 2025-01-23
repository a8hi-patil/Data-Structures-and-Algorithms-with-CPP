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
void insertAtTail(int value, ListNode *&head, ListNode *&tail)
{
    if (tail == NULL)
    {
        ListNode *newNode = new ListNode(value);
        head = newNode;
        tail = newNode;
    }
    else
    {
        ListNode *newNode = new ListNode(value);
        tail->next = newNode;
        tail = newNode;
    }
}
ListNode *detectCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast)
    {
        fast = fast->next;
        if (fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
        if (fast == slow)
        {
            break;
        }
    }
    slow = head;
    while (fast)
    {
        if (fast == slow)
        {
            return slow;
        }
    }

    return nullptr;
}
int main()
{

    return 0;
}