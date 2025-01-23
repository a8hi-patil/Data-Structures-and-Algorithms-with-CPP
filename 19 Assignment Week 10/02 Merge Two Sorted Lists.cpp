#include <iostream>
#include <cstdlib>
using namespace std;

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (list1 == NULL && list2 == NULL)
    {
        return NULL;
    }
    if (!list1)
    {
        return list2;
    }
    if (!list2)
    {
        return list1;
    }
    ListNode *ans = new ListNode(-1);
    ListNodde *mprt = ans;

    while (list1 && list2)
    {
        if (list1->val <= list2->val)
        {
            mptr->next = list1;
            mptr = list1;
            list1 = list1->next;
        }
        else
        {
            mptr->next = list2;
            mptr = list2;
            list2 = list2->next;
        }
    }
    if (list1)
    {
        mptr->next = list1;
    }
    if (list2)
    {
        mptr->next = list2;
    }
    return ans->next;
}

int main()
{
    system("cls");
    return 0;
}