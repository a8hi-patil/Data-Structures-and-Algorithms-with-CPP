#include <iostream>
#include <cstdlib>
using namespace std;
int widthOfBinaryTree(TreeNode *root)
{
    if (!root)
        return 0;
    unsigned long long maxWidth = 0;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 1});
    while (!q.empty())
    {
        unsigned long long size = q.size();
        unsigned long long left = q.front().second;
        unsigned long long right = q.front().second;
        unsigned long long width = right - left + 1;
        maxWidth = max(maxWidth, width);
        for (unsigned long long i = 0; i < size; i++)
        {
            auto front = q.front();
            q.pop();
            TreeNode *parentNode = front.first;
            unsigned long long parentIdx = front.second;
            if (parentNode->left)
            {
                q.push({parentNode->left, 2 * parentIdx});
            }
            if (parentNode->right)
            {
                q.push({parentNode->right, 2 * parentIdx + 1});
            }
        }
    }
    return maxWidth;
}
int main()
{
    system("cls");
    return 0;
}