#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <vector>
using namespace std;

ThreeNode *solve(vector<int> &preorder, int &preStart, vector<int> &inorder, int inStart, int inEnd, unordered_map<int, int> &mp)
{
    if (preStart >= preorder.size())
    {
        return NULL;
    }
    if (inStart > inEnd)
    {
        return NULL;
    }
    int el = preorder[preStart++];
    TreeNode *newNode = new TreeNode(el);
    int idx = mp[el];
    newNode->left = solve(preorder, preStart, inorder, inStart, idx - 1, mp);
    newNode->right = solve(preorder, preStart, inorder, idx + 1, inEnd, mp);
    return newNode;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int preStart = 0;
    int inStart = 0;
    int inEnd = inorder.size() - 1;
    unordered_map<int, int> mp;
    for (int i = 0; i < inorder.size(); i++)
    {
        mp[inorder[i]] = i;
    }
    return solve(preorder, preStart, inorder, inStart, inEnd, mp);
}
int main()
{
    system("cls");
    return 0;
}