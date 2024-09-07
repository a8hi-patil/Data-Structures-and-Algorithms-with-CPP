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

Node *createTree()
{
    cout << "Enter Value to Create Node : " << endl;
    int val;
    cin >> val;
    if (val == -1)
    {
        return NULL;
    }
    else
    {
        Node *root = new Node(val);
        cout << "Adding left child to "<<val << endl;
        root->left = createTree();
        cout << "Adding right child to"<< val << endl;
        root->right = createTree();
        return root;
    }
}

int main()
{
    system("cls");
    Node *root = createTree();
    return 0;
}