#include <iostream>
#include <cstdlib>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};
void solve(Node *root, int lvl, vector<int> &ans)
{
    if (!root)
        return;
    if (lvl == ans.size())
        ans.push_back(root->data);
    lvl++;
    solve(root->left, lvl, ans);
    solve(root->right, lvl, ans);
}
vector<int> leftView(Node *root)
{
    vector<int> ans;
    if (!root)
        return ans;
    int lvl = 0;
    solve(root, lvl, ans);
    return ans;
}
int main()
{
    system("cls");
    return 0;
}