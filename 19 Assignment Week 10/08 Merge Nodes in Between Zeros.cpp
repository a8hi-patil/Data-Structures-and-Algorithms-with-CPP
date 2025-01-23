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

ListNode *mergeNodes(ListNode *head)
{
    if (!head)
        return head;
    ListNode *slow = head, *fast = head->next, *newLastNode = NULL;
    int sum = 0;
    while (fast)
    {
        if (fast->data != 0)
        {
            sum += fast->data;
        }
        else
        {
            slow->data = sum;
            sum = 0;
            newLastNode = slow;
            slow = slow->next;
        }
    }
    ListNode *temp = newLastNode->next;
    newLastNode->next = NULL;

    while (temp)
    {
        ListNode *nxt = temp->next;
        delete temp;
        temp = nxt;
    }

    return head;
}
int main()
{
    system("cls");

    return 0;
}