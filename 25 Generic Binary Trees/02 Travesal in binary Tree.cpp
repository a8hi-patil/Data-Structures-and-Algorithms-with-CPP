#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->val = val;
        this->left = left;
        this->right = right;
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
void preOrderTraversal(Node *root)
{ // NLR
    if (!root)
        return;
    cout << root->val << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
void postOrderTraversal(Node *root)
{ // LRN
    if (!root)
        return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->val << " ";
}
void inOrderTraversal(Node *root)
{ // LNR
    if (!root)
        return;
    inOrderTraversal(root->left);
    cout << root->val << " ";
    inOrderTraversal(root->right);
}
void levelOrderTraversal(Node *root)
{
    if (!root)
        return;

    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        auto front = q.front();
        q.pop();
        if (front == NULL)
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << front->val << ", ";
            if (front->left)
                q.push(front->left);
            if (front->right)
                q.push(front->right);
        }
    }
}
int main()
{
    vector<int> ip = {1, 2, 3, -1, -1, 4, -1, -1, 5, 6, -1, -1, 7, -1, -1};
    int start = 0;
    Node *root = createBinaryTree(start, ip);
    cout << "Pre Order Traversal " << endl;
    preOrderTraversal(root);
    cout << endl;
    cout << "Post Order Traversal " << endl;
    postOrderTraversal(root);
    cout << endl;
    cout << "In Order Traversal " << endl;
    inOrderTraversal(root);
    cout << endl;
    cout << "Level Order Traversal " << endl;
    levelOrderTraversal(root);
    cout << endl;
    return 0;
}