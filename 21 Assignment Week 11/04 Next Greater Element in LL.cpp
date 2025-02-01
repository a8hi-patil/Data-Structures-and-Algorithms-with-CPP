#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>
using namespace std;
void solve(ListNode *head, stack<int> &st, vector<int> &op)
{
    if (!head)
    {
        return;
    }
    solve(head->next, st, op);

    while (!st.empty() && st.top() != 0 && st.top() <= head->val)
    {
        st.pop();
    }
    op.push_back(st.top());
    st.push(head->val);
}
void findNextGreater(vector<int> &ip, vector<int> &op)
{
    stack<int> st;
    st.push(0);
    for (int i = ip.size() - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() != 0 && st.top() <= ip[i])
        {
            st.pop();
        }
        op.push_back(st.top());
        st.push(ip[i]);
    }

    reverse(op.begin(), op.end());
}
int main()
{
    system("cls");
    vector<int> v;
    vector<int> ans;
    while (head)
    {
        v.push_back(head->val);
        head = head->next;
    }
    findNextGreater(v, ans);
    return ans;
    return 0;
}