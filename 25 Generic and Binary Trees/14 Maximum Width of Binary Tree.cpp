class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        unsigned long long maxWidth = 0;
        if (root == NULL)
            return maxWidth;
        queue<pair<TreeNode *, unsigned long long>> q;
        q.push({root, 1});

        while (!q.empty())
        {
            unsigned long long size = q.size();
            unsigned long long leftIdx = q.front().second;
            unsigned long long rightIdx = q.back().second;
            maxWidth = max(maxWidth, rightIdx - leftIdx + 1);

            for (int i = 0; i < size; i++)
            {
                auto front = q.front();
                unsigned long long idx = front.second;
                q.pop();

                if (front.first->left)
                {
                    q.push({front.first->left, 2 * idx});
                }
                if (front.first->right)
                {
                    q.push({front.first->right, 2 * idx + 1});
                }
            }
        }
        return maxWidth;
    }
};