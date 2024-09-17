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
        ListNode *root = NULL;
        ListNode *head = NULL;
        priority_queue<ListNode *, vector<ListNode *>, compare> pq;
        int rows = lists.size();
        for (int i = 0; i < rows; i++)
        {
            ListNode *ele = lists[i];
            if (ele != NULL)
                pq.push(ele);
        }
        while (!pq.empty())
        {
            ListNode *front = pq.top();
            pq.pop();
            if (root == NULL && head == NULL)
            {
                root = front;
                head = root;
            }
            else
            {
                head->next = front;
                head = front;
            }
            if (front->next != NULL)
            {
                pq.push(front->next);
            }
        }
        return root;
    }
};