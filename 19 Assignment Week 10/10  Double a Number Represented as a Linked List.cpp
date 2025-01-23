#include <iostream>
#include <cstdlib>
using namespace std;

ListNode *solve(ListNode *head, int &carry)
{
    if (head == NULL)
    {
        return head;
    }
    solve(head->next, carry);
    int sum = 2 * head->val + carry;
    head->val = sum % 10;
    c = sum / 10;
    return head;
}
ListNode *doubleIt(ListNode *head)
{
    int c = 0;
    ListNode *newHead = solve(head, c);
    if (c)
    {
        ListNode *fistNode = new ListNode(c);
        fistNode->next = newHead;
        return fistNode;
    }
    return newHead;
}
int main()
{
    system("cls");
    return 0;
}