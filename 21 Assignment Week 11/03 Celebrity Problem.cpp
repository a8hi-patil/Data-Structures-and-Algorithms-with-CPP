#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>
using namespace std;
int celebrity(vector<vector<int>> &mat)
{
    stack<int> st;
    for (int i = 0; i < mat.size(); i++)
    {
        st.push(i);
    }

    while (st.size() != 1)
    {
        int perA = st.top();
        st.pop();
        int perB = st.top();
        st.pop();

        if (mat[perA][perB])
        {
            st.push(perB);
        }
        else
        {
            st.push(perA);
        }
    }
    int mightBeCelebrity = st.top();

    for (int i = 0; i < mat.size(); i++)
    {
        if (mat[mightBeCelebrity][i] != 0)
            return -1;
    }
    for (int i = 0; i < mat.size(); i++)
    {
        if (mat[i][mightBeCelebrity] != 1 && i != mightBeCelebrity)
            return -1;
    }
    return mightBeCelebrity;
}
int main()
{
    system("cls");
    return 0;
}