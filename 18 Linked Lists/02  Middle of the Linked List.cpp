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
int findMid(ListNode *&head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        else
        {
            break;
        }
    }
    return slow->data;
}
int main()
{
    system("cls");
    ListNode *head = NULL;
    ListNode *tail = NULL;

    head = insertAthead(5, head, tail);
    head = insertAthead(4, head, tail);
    head = insertAthead(3, head, tail);
    head = insertAthead(2, head, tail);
    head = insertAthead(1, head, tail);
    printLL(head);
    cout << findMid(head);
    return 0;
}