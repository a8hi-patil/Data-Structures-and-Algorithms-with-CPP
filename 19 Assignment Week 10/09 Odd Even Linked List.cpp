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
ListNode *oddEvenList(ListNode *head)
{
    if (!head || !head->next || !head->next->next)
    {
        return head;
    }
    ListNode *h1 = head;
    ListNode *h3 = head->next;
    ListNode *h2 = head->next;

    while (h2 && h2->next)
    {
        h1->next = h2->next;
        h1 = h1->next;
        h2->next = h1->next;
        h2 = h1->next;
    }
    h1->next = h3;
    return head;
}
int main()
{
    system("cls");
    return 0;
}