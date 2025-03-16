#include <iostream>
#include <cstdlib>
using namespace std;
void solve(Node *root, Node *&head, Node *&tail)
{
    if (!root)
        return;
    solve(root->left, head, tail);
    if (tail)
    {
        tail->right = root;
        root->left = tail
            tail = root;
    }
    else
    {
        tail = root;
        head = root;
    }
    solve(root->right, head, tail);
}
int main()
{
    system("cls");
    return 0;
}