#include <iostream>
#include <cstdlib>
#include <unordered_map>
using namespace std;

//  * Definition for singly-linked list.
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
    void sanitizeMap(ListNode *curr, unordered_map<int, ListNode *> &mp, int cSum)
    {
        int temp = cSum;
        while (true)
        {
            temp += curr->val;
            if (temp == cSum)
                break;
            mp.erase(temp);
            curr = curr->next;
        }
    }

    ListNode *removeZeroSumSublists(ListNode *head)
    {
        if (!head || (!head->next && head->val == 0))
            return 0;
        unordered_map<int, ListNode *> mp;
        ListNode *it = head;
        int cSum = 0;

        while (it)
        {
            cSum = it->val;
            if (cSum == 0)
            {
                head = it->next;
                mp.clear();
            }
            else if (mp.find(cSum) != mp.end())
            {
                sanitizeMap(mp[cSum]->next, mp, cSum);
                mp[cSum]->next = it;
            }
            else
            {
                mp[cSum] = it;
            }

            it = it->next;
        }
        return head;
    }
};
int main()
{
    system("cls");
    return 0;
}