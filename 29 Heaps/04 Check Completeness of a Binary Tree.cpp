#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;
bool isCompleteTree(TreeNode *root)
{
    if (!root)
        return true;

    queue<TreeNode *> q;
    q.push(root);
    bool isNUllFound = false;
    while (!q.empty())
    {
        auto front = q.front();
        q.pop();
        if (front == nullptr)
        {
            isNullFound = true;
        }
        else
        {
            if (isNullFound)
                return false;
            q.push(front->left);
            q.push(front->right);
        }
    }
    return true;
}
int main()
{
    system("cls");
    return 0;
}