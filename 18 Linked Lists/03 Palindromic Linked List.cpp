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

ListNode *insertAthead(int val, ListNode *&head, ListNode *tail)
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
void printLL(ListNode *head)
{
    ListNode *temp = head;
    while (temp)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
ListNode *getMid(ListNode *head)
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
    }
    return slow;
}
ListNode *rev(ListNode *head)
{
    ListNode *curr = head->next;
    if (!curr)
    {
        return head;
    }
    ListNode *prev = NULL;

    while (curr)
    {

        ListNode *nextNode = curr->next;
        curr->next = prev;
        curr = nextNode;
    }
    return prev;
}
bool isPalindrom(ListNode *head)
{
    if (head == NULL)
    {
        return true;
    }
    if (head->next == NULL)
    {
        return true;
    }
    ListNode *mid = getMid(head);
    cout << "mid " << mid->data << endl;
    ListNode *reversedLLHead = rev(mid);
    cout << "R " << reversedLLHead->data << endl;
    mid->next = NULL;
    ListNode *tempHead = head;
    while (tempHead && reversedLLHead)
    {
        cout << tempHead->data << " " << reversedLLHead->data << endl;
        if (tempHead->data != reversedLLHead->data)
        {
            return false;
        }
        tempHead = tempHead->next;
        reversedLLHead = reversedLLHead->next;
    }
    return true;
}
int main()
{
    system("cls");
    ListNode *head = NULL;
    ListNode *tail = NULL;

    head = insertAthead(1, head, tail);
    head = insertAthead(2, head, tail);
    printLL(head);
    isPalindrom(head);

    return 0;
}