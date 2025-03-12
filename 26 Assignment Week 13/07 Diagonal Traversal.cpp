#include <iostream>
#include <cstdlib>
using namespace std;

vector<int> diagonalTraversal(TreeNode *root)
{
    vector<int> ans;
    if (!root)
        return ans;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *front = q.front();
        q.pop();

        while (front)
        {
            ans.push_back(front->data);
            if (front->left)
            {
                q.push(front->left);
            }
            front = front->right;
        }
    }
    return ans;
}

int main()
{
    system("cls");
    return 0;
}