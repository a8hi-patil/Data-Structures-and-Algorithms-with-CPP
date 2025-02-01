#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
void findNextSmaller(vector<int> &inp, vector<int> &op)
{
    stack<int> st;
    st.push(-1);

    for (int i = inp.size() - 1; i >= 0; i--)
    {
        int el = inp[i];
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
    vector<int> v = {8, 4, 5, 2, 3};
    vector<int> ans;
    findNextSmaller(v, ans);
    reverse(ans.begin(), ans.end());
    for (auto a : ans)
    {
        cout << a << " ";
    }
    return 0;
}