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
Node *BSF(Node *root, int val)
{
    if (root == NULL)
    {
        root = new Node(val);
        return root;
    }
    if (val < root->data)
    {
        root->left = BSF(root->left, val);
    }
    else
    {
        root->right = BSF(root->right, val);
    }
    return root;
}

void levelOrderTraversal(Node *root)
{
    if (!root)
    {
        cout << "Tree is empty " << endl;
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

Node *createBST()
{
    cout << "Enter Root Node " << endl;
    int val;
    cin >> val;
    Node *root = NULL;

    while (val != -1)
    {
        root = BSF(root, val);
        cout << "Enter child Node " << endl;
        cin >> val;
    }
    return root;
}
bool search(Node *root, int target)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == target)
    {
        return true;
    }
    else
    {
        if (root->data > target)
        {
            bool left = search(root->left, target);
            if (left)
                return true;
        }
        else
        {
            bool right = search(root->right, target);
            if (right)
                return true;
        }
    }
    return false;
}
int main()
{
    system("cls");
    Node *root = createBST();
    bool ans = search(root, 200);
    if (ans)
        cout << "node found";
    else
        cout << "node not found";
    return 0;
}