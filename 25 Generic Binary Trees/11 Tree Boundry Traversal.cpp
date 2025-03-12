#include <iostream>
#include <cstdlib>
using namespace std;
void leftBoundry(Node *root, vector<int> &ans)
{
    if (!root)
        return;
    if (!root->left && !root->right)
        return;
    ans.push_back(root->data);
    if (root->left)
    {
        leftBoundry(root->left, ans);
    }
    else
    {
        leftBoundry(root->right, ans);
    }
}
void rightBoundry(Node *root, vector<int> &ans)
{
    if (!root)
        return;
    if (!root->left && !root->right)
        return;
    if (root->right)
    {
        rightBoundry(root->right, ans);
    }
    else
    {
        rightBoundry(root->left, ans);
    }
    ans.push_back(root->data);
}
void leafBoundry(Node *root, vector<int> &ans)
{
    if (!root)
        return;
    if (!root->left && !root->right)
        ans.push_back(root->data);

    leafBoundry(root->left, ans);
    leafBoundry(root->right, ans);
}
vector<int> boundaryTraversal(Node *root)
{
    vector<int> ans;
    if (!root)
        return ans;

    ans.push_back(root->data);
    leftBoundry(root->left, ans);
    leafBoundry(root->left, ans);
    leafBoundry(root->rigth, ans);
    rightBoundry(root->rigth, ans);
    return ans;
}

int main()
{
    system("cls");
    return 0;
}