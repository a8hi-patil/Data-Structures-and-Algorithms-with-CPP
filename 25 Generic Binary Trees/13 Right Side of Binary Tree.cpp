#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

void solve(Node *root, int lvl, vector<int> &ans)
{
    if (!root)
        return;
    if (lvl == ans.size())
        ans.push_back(root->data);
    solve(root->right, lvl + 1, ans);
    solve(root->left, lvl + 1, ans);
}
vector<int> rightView(Node *root)
{
    vector<int> ans;
    if (!root)
        return ans;
    solve(root, 0, ans);
    return ans;
}
int main()
{
    system("cls");
    return 0;
}