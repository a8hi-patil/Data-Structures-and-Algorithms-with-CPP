#include <iostream>
#include <cstdlib>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
};
void createParentMapping(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &mp)
{
    if (!root)
        return;

    if (root->left)
    {
        mp[root->left] = root;
        createParentMapping(root->left, mp);
    }
    if (root->right)
    {
        mp[root->right] = root;
        createParentMapping(root->right, mp);
    }
}
vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    vector<int> ans;
    if (!root)
        return ans;
    unordered_map<TreeNode *, TreeNode *> mp;
    createParentMapping(root, mp);
    unordered_map<TreeNode *, bool> vis;
    queue<TreeNode *> q;
    q.push(target);
    vis[target] = true;
    int lvl = 0;
    while (!q.empty())
    {
        int size = q.size();
        if (lvl == k)
            break;
        lvl++;
        for (int i = 0; i < size; i++)
        {
            TreeNode *front = q.front();
            q.pop();

            if (front->left && vis.find(front->left) == vis.end())
            {
                q.push(front->left);
                vis[front->left] = true;
            }
            if (front->right && vis.find(front->right) == vis.end())
            {
                q.push(front->right);
                vis[front->right] = true;
            }
            TreeNode *parentNode = mp[front];
            if (parentNode && vis.find(parentNode) == vis.end())
            {
                q.push(parentNode);
                vis[parentNode] = true;
            }
        }
    }
    while (!q.empty())
    {
        TreeNode *f = q.front();
        q.pop();
        ans.push_back(f->data);
    }
    return ans;
}

int main()
{
    system("cls");
    return 0;
}