#include <iostream>
#include <cstdlib>
using namespace std;
int leftH(TreeNode *root)
{
    int c = 0;
    while (root)
    {
        c++;
        root = root->left;
    }
    return c;
}
int rightH(TreeNode *root)
{
    int c = 0;
    while (root)
    {
        c++;
        root = root->right;
    }
    return c;
}

int countNodes(TreeNode *root)
{
    if (!root)
        return 0;

    int l = leftH(root);
    int r = rightH(root);
    if (l == r)
        return (1 << l) - 1;
    int lans = countNodes(root->left);
    int rans = countNodes(root->right);
    return 1 + lans + rans;
}
int main()
{
    system("cls");
    return 0;
}