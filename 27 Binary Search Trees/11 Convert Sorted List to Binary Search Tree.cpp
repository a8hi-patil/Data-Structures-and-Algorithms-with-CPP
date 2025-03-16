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
    TreeNode *solve(ListNode *&head, int n)
    {
        if (!head || n <= 0)
        {
            return nullptr;
        }
        TreeNode *lans = solve(head, n / 2);
        TreeNode *root = new TreeNode(head->val);
        head = head->next;
        root->left = lans;
        TreeNode *rans = solve(head, n - n / 2 - 1);
        root->right = rans;
        return root;
    }
    TreeNode *sortedListToBST(ListNode *head)
    {
        int n = getLength(head);
        TreeNode *ans = solve(head, n);
        return ans;
    }
};