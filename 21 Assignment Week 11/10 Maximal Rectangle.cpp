#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

void findNextSmall(vector<int> &ip, vector<int> &op)
{

    stack<int> st;
    st.push(-1);
    for (int i = ip.size() - 1; i >= 0; i--)
    {
        int ele = ip[i];
        // 3 4 6 7 8 1 2
        while (!st.empty() && st.top() != -1 && ip[st.top()] >= ele)
        {
            st.pop();
        }
        op.push_back(st.top());
        st.push(i);
    }
    reverse(op.begin(), op.end());
}
void findPrevSmall(vector<int> &ip, vector<int> &op)
{

    stack<int> st;
    st.push(-1);
    for (int i = 0; i < ip.size(); i++)
    {
        int ele = ip[i];
        // 3 4 6 7 8 1 2
        while (!st.empty() && st.top() != -1 && ip[st.top()] >= ele)
        {
            st.pop();
        }
        op.push_back(st.top());
        st.push(i);
    }
}

int calMaxArea(vector<int> ip)
{

    vector<int> nextSmaller;
    vector<int> prevSmaller;
    findPrevSmall(ip, prevSmaller);
    findNextSmall(ip, nextSmaller);
    for (int i = 0; i < nextSmaller.size(); i++)
    {
        nextSmaller[i] = nextSmaller[i] == -1 ? nextSmaller.size() : nextSmaller[i];
    }
    int maxArea = INT_MIN;

    for (int i = 0; i < nextSmaller.size(); i++)
    {
        int width = nextSmaller[i] - prevSmaller[i] - 1;
        int area = width * ip[i];
        // cout << area << endl;
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

int main()
{
    system("cls");
    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'},
                                   {'1', '0', '1', '1', '1'},
                                   {'1', '1', '1', '1', '1'},
                                   {'1', '0', '0', '1', '0'}};

    vector<vector<int>> v;
    for (auto a : matrix)
    {
        vector<int> t;
        for (int i = 0; i < a.size(); i++)
        {
            t.push_back(a[i] - '0');
        }

        v.push_back(t);
    }
    int maxArea = calMaxArea(v[0]);

    for (int i = 1; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            if (v[i][j])
            {
                v[i][j] += v[i - 1][j];
            }
            else
            {
                v[i][j] = 0;
            }
        }

        int x = calMaxArea(v[i]);
        maxArea = max(maxArea, x);
    }
    cout << maxArea;

    return 0;
}