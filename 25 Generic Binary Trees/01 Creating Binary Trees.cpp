#include <iostream>
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
Node *createBinaryTree()
{
    int val;
    cout << "Enter value to add " << endl;
    cin >> val;

    if (val == -1)
    {
        return NULL;
    }
    else
    {
        Node *newRoot = new Node(val);
        cout << "Adding left child to " << val << endl;
        newRoot->left = createBinaryTree();
        cout << "Adding right child to " << val << endl;
        newRoot->right = createBinaryTree();
        return newRoot;
    }
}
int main()
{
    Node *root = createBinaryTree();
}