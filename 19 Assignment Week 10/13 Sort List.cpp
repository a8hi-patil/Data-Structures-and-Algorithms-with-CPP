#include <iostream>
#include <cstdlib>
using namespace std;

//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *findMid(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode *merge(ListNode *list1, ListNode *list2)
    {

        if (list1 == NULL && list2 == NULL)
        {
            return NULL;
        }
        if (list1 == NULL)
        {
            return list2;
        }
        if (list2 == NULL)
        {
            return list1;
        }

        ListNode *ans = new ListNode(-1);
        ListNode *mptr = ans;
        ListNode *l1 = list1;
        ListNode *l2 = list2;

        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                mptr->next = l1;
                mptr = l1;
                l1 = l1->next;
            }
            else
            {
                mptr->next = l2;
                mptr = l2;
                l2 = l2->next;
            }
        }
        if (!l1)
        {
            mptr->next = l2;
        }
        if (!l2)
        {
            mptr->next = l1;
        }
        return ans->next;
    }
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }
        ListNode *left = head;
        ListNode *mid = findMid(head);
        ListNode *right = mid->next;
        mid->next = NULL;

        left = sortList(left);
        right = sortList(right);

        ListNode *mergedLL = merge(left, right);
        return mergedLL;
    }
};
int main()
{
    system("cls");
    return 0;
}