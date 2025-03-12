#include <iostream>
#include <cstdlib>
using namespace std;

int ans = 0;

void solve(TreeNode *root, int target)
{
    if (!root)
        return;

    if (target - root->val == 0)
    {
        ans++;
    }
    solve(root->left, target - root->val);
    solve(root->right, target - root->val);
}
void findPath(TreeNode *root, int target)
{
    if (!root)
        return;
    solve(root, target);
    findPath(root->left, target);
    findPath(root->right, target);
}
int pathSum(TreeNode *root, int targetSum)
{
    findPath(root, targetSum);
    return ans;
}
int main()
{
    system("cls");
    return 0;
}