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
        this->left = nullptr;
        this->right = nullptr;
    }
};
Node *createBST(int val, Node *root)
{
    if (root == nullptr)
    {
        Node *newRoot = new Node(val);
        return newRoot;
    }
    else
    {
        if (val < root->data)
        {
            root->left = createBST(val, root->left);
        }
        else
        {
            root->right = createBST(val, root->right);
        }
    }
    return root;
}
Node *createTree()
{
    int val;
    cout << "Enter Value : ";
    cin >> val;
    Node *root = nullptr;
    while (val != -1)
    {
        root = createBST(val, root);
        cout << "Enter Value : ";
        cin >> val;
    }
    return root;
}
void levelOrderTraversal(Node *root)
{
    if (!root)
        return;
    queue<Node *> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (front == nullptr)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(nullptr);
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
int getMin(Node *root)
{
    if (!root)
        return -1;
    while (root->left)
    {
        root = root->left;
    }
    return root->data;
}
int getMax(Node *root)
{
    if (!root)
        return -1;
    while (root->right)
    {
        root = root->right;
    }
    return root->data;
}

int main()
{
    system("cls");
    Node *root = createTree();
    levelOrderTraversal(root);
    cout << endl
         << "Min : " << getMin(root);
    cout << endl
         << "Max : " << getMax(root);
    return 0;
}