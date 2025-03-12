#include <iostream>
#include <cstdlib>
using namespace std;
class Codec
{
public:
    void solve(TreeNode *root, string &ans)
    {
        if (!root)
        {
            ans += "#,";
            return;
        }
        string n = to_string(root->val);
        ans += n;
        ans += ",";
        solve(root->left, ans);
        solve(root->right, ans);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string ans = "";
        solve(root, ans);
        cout << ans << endl;
        return ans;
    }

    TreeNode *solveD(string data, int &start)
    {

        if (start >= data.length())
        {
            return NULL;
        }
        string num = "";
        while (data[start] != ',')
        {
            num += data[start++];
        }

        start++;
        if (num == "#")
            return NULL;
        int nm = stoi(num);
        TreeNode *root = new TreeNode(nm);
        root->left = solveD(data, start);
        root->right = solveD(data, start);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        int start = 0;

        TreeNode *root = solveD(data, start);
        return root;
    }
};

int main()
{
    system("cls");
    return 0;
}