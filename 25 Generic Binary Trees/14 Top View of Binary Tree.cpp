#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

vector<int> topView(Node *root)
{
    vector<int> ans;
    if (!root)
        return ans;
    int mini = 0;
    int maxi = 0;
    queue<pair<Node *, int>> q;
    unordered_map<int, Node *> mp;
    q.push({root, 0});
    while (!q.empty())
    {
        auto front = q.front();
        q.pop();
        it hd = front.second;
        mini = min(mini, hd);
        maxi = max(maxi, hd);
        if (mp.find(hd) == mp.end())
        {
            mp[hd] = front.first;
        }
        if (front.first->left)
        {
            q.push({front.first->left, hd - 1});
        }
        if (front.first->right)
        {
            q.push({front.first->right, hd + 1});
        }
    }
    for (int i = mini; i <= maxi; i++)
    {
        ans.push_back(mp[i]->data);
    }
    return ans;
}
int main()
{
    system("cls");
    return 0;
}