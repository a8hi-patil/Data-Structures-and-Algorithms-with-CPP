class Solution
{
public:
    int countPairs(Node *root1, Node *root2, int x)
    {
        stack<Node *> s1;
        stack<Node *> s2;
        Node *a = root1;
        Node *b = root2;
        int ans = 0;
        while (1)
        {
            while (a)
            {
                s1.push(a);
                a = a->left;
            }
            while (b)
            {
                s2.push(b);
                b = b->right;
            }
            if (s1.empty() || s2.empty())
            {
                break;
            }
            auto atop = s1.top();
            auto btop = s2.top();
            int sum = atop->data + btop->data;
            if (sum == x)
            {
                ans++;
                s1.pop();
                s2.pop();
                a = atop->right;
                b = btop->left;
            }
            else if (sum > x)
            {
                s2.pop();
                b = btop->left;
            }
            else
            {
                s1.pop();
                a = atop->right;
            }
        }
        return ans;
    }
};