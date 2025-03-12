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
int diameterOfTree(Node *root)
{
    if (!root)
        return 0;
    int left = diameterOfTree(root->left);
    int right = diameterOfTree(root->right);
    int both = getHeight(root->left) + getHeight(root->right);
}
int main()
{
    system("cls");
    return 0;
}