#include <iostream>
#include <cstdlib>
#include <queue>
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

Node *createTree()
{
    // cout << "Enter Value to Create Node : " << endl;
    int val;
    cin >> val;
    if (val == -1)
    {
        return NULL;
    }
    else
    {
        Node *root = new Node(val);
        // cout << "Adding left child to " << val << endl;
        root->left = createTree();
        // cout << "Adding right child to" << val << endl;
        root->right = createTree();
        return root;
    }
}

void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    // NLR
    cout << root->data << endl;
    preOrder(root->left);
    preOrder(root->right);
};
void postOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    // LRN
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << endl;
};
void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    // LNR
    inOrder(root->left);
    cout << root->data << endl;
    inOrder(root->right);
};
void levelOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (front == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << front->data << " ";
            if (front->left)
            {
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }
        }
    }
}
int main()
{
    system("cls");
    Node *root = createTree();
    // 10 50 40 -1 -1 -1 30 20 -1 -1 -1
    levelOrder(root);
    return 0;
}