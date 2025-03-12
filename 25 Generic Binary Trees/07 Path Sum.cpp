#include <iostream>
#include <cstdlib>
using namespace std;
bool pathSum(Node *root, int target)
{
    if (!root)
    {
        return false;
    }
    if (!root->left && !root->right)
    {
        return target - root->val == 0;
    }
    return pathSum(root->left, target - root->left) || pathSum(root->left, target - root->right);
}
int main()
{
    system("cls");
    return 0;
}