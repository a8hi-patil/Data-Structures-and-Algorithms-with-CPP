#include <iostream>
#include <cstdlib>
using namespace std;
int getHeight(TreeNode *root, bool &ans)
{
    if (!root)
        return 0;
    int l = getHeight(root->left);
    int r = getHeight(root->right);
    if (ans && abs(l - r) > 1)
    {
        ans = false;
    }
    return 1 + max(l, r);
}
int main()
{
    system("cls");
    return 0;
}