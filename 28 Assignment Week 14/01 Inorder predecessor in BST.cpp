/* This is the Node class definition

class Node {
public:
    Node* left;
    Node* right;
    int data;

    Node(int data) {
        this->left = NULL;
        this->right = NULL;
        this->data = data;
    }
};
*/

void solve(Node *root, Node *p, Node *&ans)
{
    if (!root)
        return;

    if (root->data < p->data)
    {
        ans = root;
        solve(root->right, p, ans);
    }
    else
    {
        solve(root->left, p, ans);
    }
}

Node *findPredecessor(Node *root, Node *p)
{
    Node *ans = nullptr;
    solve(root, p, ans);
    return ans;
}