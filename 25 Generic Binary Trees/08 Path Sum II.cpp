#include <iostream>
#include <cstdlib>
using namespace std;

void solve(TreeNode *root, int target, vector<vector<int>> &ans, vector<int> &temp)
{
    if (!root)
        return;
    target = target - root->data;
    temp.push_back(root->data);
    if (!root->left && !root->right)
    {
        if (target == 0)
        {
            ans.push_back(temp);
            temp.pop_back();
        }
        return;
    }
    solve(root->left, target, ans, temp);
    solve(root->right, target, ans, temp);
    temp.pop_back();
}

vector<vector<int>> pathSum(TreeNode *root, int targetSum)
{
    vector<vector<int>> ans;
    vector<int> temp;
    solve(root, targetSum, ans, temp);
    return ans;
}
int main()
{
    system("cls");
    return 0;
}
