#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>
using namespace std;
void prevSmaller(vector<int> &ip, vector<int> &op)
{
    stack<int> st;
    st.push(-1);
    for (int i = 0; i < ip.size(); i++)
    {
        int el = ip[i];
        while (st.top() > el)
        {
            st.pop();
        }
        op.push_back(st.top());
        st.push(el);
    }
}
int main()
{
    system("cls");
    vector<int> v = {4, 2, 0, 3, 2, 4, 3, 4};
    vector<int> ans;
    prevSmaller(v, ans);

    for (auto a : ans)
    {
        cout << a << " ,";
    }
    return 0;
}