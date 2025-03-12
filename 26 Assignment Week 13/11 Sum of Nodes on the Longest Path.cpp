#include <iostream>
#include <cstdlib>
using namespace std;

pair<int, int> solve(Node *root)
{
    if (!root)
    {
        return {0, 0};
    }
    auto l = solve(root->left);
    auto r = solve(root->right);
    int sum = root->data;

    if (l.first == r.first)
    {
        sum += l.second ? r.second ? l.second : r.second;
    }
    else if (l.first > r.first)
    {
        sum += l.second;
    }
    else
    {
        sum += r.second;
    }
    return {max(l.fist, r.fist) + 1, sum};
}
int sumOfLongRootToLeafPath(Node *root)
{
    auto ans = solve(root);
    return ans.second;
}
int main()
{
    system("cls");
    return 0;
}