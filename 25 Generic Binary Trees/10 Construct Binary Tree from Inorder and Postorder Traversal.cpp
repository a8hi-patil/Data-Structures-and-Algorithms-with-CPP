#include <iostream>
#include <cstdlib>
using namespace std;
TreeNode *solve(vector<int> &inorder, int inS, int inE,
                vector<int> &postorder, int &posE,
                unordered_map<int, int> &mp)
{
    if (posE < 0)
    {
        return NULL;
    }
    if (inS > inE)
        return NULL;
    int el = postorder[posE--];
    TreeNode *newNode = new TreeNode(el);
    int idx = mp[el];
    newNode->right = solve(inorder, idx + 1, inE, postorder, posE, mp);
    newNode->left = solve(inorder, inS, idx - 1, postorder, posE, mp);
    return newNode;
}
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < inorder.size(); i++)
    {
        mp[inorder[i]] = i;
    }
    int postE = postorder.size() - 1;
    int inS = 0;
    int insE = inorder.size() - 1;
    return solve(inorder, inS, insE, postorder, postE, mp);
}
int main()
{
    system("cls");
    return 0;
}