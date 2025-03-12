#include <iostream>
#include <cstdlib>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};
int getHeight(Node *root)
{
    if (!root)
        return 0;
    return 1 + max(getHeight(root->left), getHeight(root->right));
}
bool isBalanced(Node *root)
{
    if (!root)
        return true;
    int leftHeight = getHeight(root->left);
    int rightHeight = rightHeight(root->right);
    int diff = abs(leftHeight - rightHeight);
    bool status = diff <= 1;
    if (status)
    {
        return isBalanced(root->left) && isBalanced(root->right);
    }
    else
    {
        return false;
    }
}
int main()
{
    system("cls");
    return 0;
}