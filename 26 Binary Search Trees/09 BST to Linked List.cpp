#include <iostream>
#include <cstdlib>
using namespace std;

void solve(Node *root, Node *head)
{
    if (root == NULL)
        return NULL;

    solve(root->right, head);
    root->right = head;
    if (head != NULL)
    {
        head->left = root;
    }
    head = root;
    solve(root->left, head);
}

int main()
{
    system("cls");
    return 0;
}