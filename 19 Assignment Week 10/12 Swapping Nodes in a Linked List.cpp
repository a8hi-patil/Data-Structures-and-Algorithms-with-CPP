/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    int getLength(ListNode *head)
    {
        int c = 0;
        ListNode *temp = head;
        while (temp)
        {
            c++;
            temp = temp->next;
        }
        return c;
    }

    ListNode *swapNodes(ListNode *head, int k)
    {
        if (!head)
            return head;
        int len = getLength(head);
        if (k > len)
            return head;
        int leftPos = k;
        int rightPos = len - k + 1;
        if (leftPos == rightPos)
            return head;

        ListNode *itL = head;
        for (int i = 0; i < leftPos - 1; i++)
        {
            itL = itL->next;
        }
        ListNode *itR = head;
        for (int i = 0; i < rightPos - 1; i++)
        {
            itR = itR->next;
        }
        int temp = itL->val;
        itL->val = itR->val;
        itR->val = temp;
        return head;
    }
};