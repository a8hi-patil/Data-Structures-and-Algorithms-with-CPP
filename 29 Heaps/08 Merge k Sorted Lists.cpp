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

class compare
{
public:
    bool operator()(ListNode *a, ListNode *b) { return a->val > b->val; }
};
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, compare> pq;
        ListNode *head = nullptr;
        ListNode *tail = nullptr;
        for (int i = 0; i < lists.size(); i++)
        {
            ListNode *ele = lists[i];
            if (ele != NULL)
                pq.push(ele);
        }
        while (!pq.empty())
        {
            auto node = pq.top();
            pq.pop();
            if (!head && !tail)
            {
                head = node;
                tail = node;
            }
            else
            {
                tail->next = node;
                tail = node;
            }
            if (node->next != nullptr)
            {
                pq.push(node->next);
            }
        }
        return head;
    }
};