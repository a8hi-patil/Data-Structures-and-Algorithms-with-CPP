#include <iostream>
#include <cstdlib>
#include <vector>
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
Node *createBinaryTree(int &start, vector<int> &ip)
{
    if (start >= ip.size())
    {
        return NULL;
    }
    if (ip[start] == -1)
    {
        start++;
        return NULL;
    }
    else
    {
        Node *newRoot = new Node(ip[start]);
        start++;
        newRoot->left = createBinaryTree(start, ip);
        newRoot->right = createBinaryTree(start, ip);
        return newRoot;
    }
}
int solve(Node *root)
{
    if (!root)
        return 0;
    return 1 + max(solve(root->left), solve(root->right));
}
int maxDepth(Node *root)
{
    return solve(root);
}
int main()
{
    system("cls");
    vector<int> ip = {3, 9, 20, -1, -1, 15, 7};
    int start = 0;
    Node *root = createBinaryTree(start, ip);
    cout << maxDepth(root);
    return 0;
}