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

    ListNode *cNode = head;
    while (cNode)
    {
        if (mp[cNode] == true)
        {
            return true;
        }
        else
        {
            mp[cNode] = true;
        }

        cNode = cNode->next;
    }

    return false;
}
bool detectCycle2(ListNode *head)
{
    ListNode *tortoise = head;
    ListNode *hair = head;

    while (hair)
    {
        hair = hair->next;
        if (hair)
        {
            hair = hair->next;
            tortoise = tortoise->next;
        }
        if (hair == tortoise)
            return true;
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