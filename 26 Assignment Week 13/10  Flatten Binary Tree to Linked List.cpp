#include <iostream>
#include <cstdlib>
using namespace std;

TreeNode *curr = root;
while (curr)
{
    if (curr->left)
    {
        TreeNode *pred = curr->left;
        while (pred->right)
        {
            pred = pred->right;
        }
        pred->right = curr->right;
        curr->right = curr->left;
        curr->left = nullptr;
    }
    curr = curr->right;
}
int main()
{
    system("cls");
    return 0;
}