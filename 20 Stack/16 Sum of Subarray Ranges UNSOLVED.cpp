#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
void findNextSmaller(vector<int> &ip, vector<int> &op)
{
    stack<int> st;
    st.push(-1);
    for (int i = ip.size(); i >= 0; i--)
    {
        while ((!st.empty() && st.top() != -1 && ip[st.top()] >= ip[i]))
        {
            st.pop();
        }
        op.push_back(st.top());
        st.push(i);
    }
    reverse(op.begin(), op.end());
}
void findPrevSmaller(vector<int> &ip, vector<int> &op)
{
    stack<int> st;
    st.push(-1);
    for (int i = 0; i < ip.size(); i++)
    {
        while ((!st.empty() && st.top() != -1 && ip[st.top()] > ip[i]))
        {
            st.pop();
        }

        op.push_back(st.top());
        st.push(i);
    }
}

void findNextGreater(vector<int> &ip, vector<int> &op)
{
    stack<int> st;
    st.push(-1);
    for (int i = ip.size() - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() != -1 && ip[st.top()] < ip[i])
        {
            st.pop();
        }
        op.push_back(st.top());
        st.push(i);
    }
    reverse(op.begin(), op.end());
}
void findPrevGreater(vector<int> &ip, vector<int> &op)
{
    stack<int> st;
    st.push(-1);
    for (int i = 0; i < ip.size(); i++)
    {
        while (!st.empty() && st.top() != -1 && ip[st.top()] <= ip[i])
        {
            st.pop();
        }
        op.push_back(st.top());
        st.push(i);
    }
}

int sumAll(vector<int> &ip, vector<int> &next, vector<int> &prev)
{
    int sum = 0;

    for (int i = 0; i < ip.size(); i++)
    {
        int nexti = next[i] == -1 ? ip.size() : next[i];
        int previ = prev[i];
        int right = nexti - i;
        int left = i - previ;
        sum = sum + right * left * ip[i];
    }
    return sum;
}
int main()
{
    system("cls");
    vector<int> ip = {1, 2, 3};

    vector<int> nextSmaller;
    vector<int> prevSmaller;
    findNextSmaller(ip, nextSmaller);
    findPrevSmaller(ip, prevSmaller);
    vector<int> nextGreater;
    vector<int> prevGreater;
    findNextGreater(ip, nextGreater);
    findPrevGreater(ip, prevGreater);

    int sumSmaller = sumAll(ip, nextSmaller, prevSmaller);
    int sumGreater = sumAll(ip, nextGreater, prevGreater);
    cout << sumGreater - sumSmaller << endl;

    return 0;
}