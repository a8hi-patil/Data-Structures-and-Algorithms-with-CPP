#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

void findnextSmaller(vector<int> &ip, vector<int> &op)
{
    stack<int> st;
    st.push(-1);
    for (int i = ip.size() - 1; i >= 0; i--)
    {
        int el = ip[i];
        while (!st.empty() && st.top() != -1 && el <= ip[st.top()])
        {
            st.pop();
        }
        op.push_back(st.top());
        st.push(i);
    }
    reverse(op.begin(), op.end());
}
void findprevSmaller(vector<int> &ip, vector<int> &op)
{
    stack<int> st;
    st.push(-1);
    for (int i = 0; i < ip.size(); i++)
    {
        int el = ip[i];
        while (!st.empty() && st.top() != -1 && el <= ip[st.top()])
        {
            st.pop();
        }
        op.push_back(st.top());
        st.push(i);
    }
}

int main()
{
    system("cls");
    vector<int> v = {2, 1, 5, 6, 2, 3};
    vector<int> nextSmall;
    vector<int> prevSmall;
    vector<int> ans;
    findnextSmaller(v, nextSmall);
    findprevSmaller(v, prevSmall);
    for (int i = 0; i < nextSmall.sizse(); i++)
    {
        if (nextSmall[i] == -1)
        {
            nextSmall[i] = nextSmall.size();
        }
    }
    int maxArea = 0;
    for (int i = 0; i < nextSmall.size(); i++)
    {
        int width = nextSmall[i] - prevSmall[i] - 1;
        int area = width * v[i];
        if (area > maxArea)
        {
            maxArea = area;
        }
    }
    cout << "Max Area " << maxArea << endl;

    return 0;
}