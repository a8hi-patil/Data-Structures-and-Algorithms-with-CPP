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

bool detectCycle(ListNode *head)
{
    unordered_map<ListNode *, bool> mp;
    ListNode *currentNode = head;
    while (currentNode != NULL)
    {
        if (mp[currentNode] == true)
        {
            return true;
        }
        else
        {
            mp[currentNode] = true;
        }
        currentNode = currentNode->next;
    }
    return false;
}
bool detectCycle2(ListNode *head)
{
    ListNode *tortoise = head;
    ListNode *hare = head;
    while (hare != NULL)
    {
        if (hare == tortoise)
        {
            return true;
        }
        hare = hare->next;
        if (hare != NULL)
        {
            hare = hare->next;
            tortoise = tortoise->next;
        }
    }
    return false;
}
int main()
{
    system("cls");
    ListNode *head = NULL;
    ListNode *tail = NULL;
    insertAtHead(10, head, tail);
    insertAtHead(20, head, tail);
    ListNode *tempHead = head;
    insertAtHead(30, head, tail);
    insertAtHead(40, head, tail);
    tail->next = tempHead;
    // print(head);
    cout << detectCycle(head) << endl;
    cout << detectCycle2(head) << endl;
    return 0;
}