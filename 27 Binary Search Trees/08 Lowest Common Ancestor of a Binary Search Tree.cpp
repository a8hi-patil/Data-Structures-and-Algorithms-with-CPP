#include <iostream>
#include <cstdlib>
using namespace std;

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (!root)
        return root;
    if (p->val < root->val && q->val < root - val)
    {
        TreeNode *lAns = lowestCommonAncestor(root->left, p, q);
        if (lAns)
            return lAns;
    }
    if (p->val > root->val && q->val > root - val)
    {
        TreeNode *rAns = lowestCommonAncestor(root->right, p, q);
        if (rAns)
            return rAns;
    }
    return root;
}

int main()
{
    system("cls");
    return 0;
}