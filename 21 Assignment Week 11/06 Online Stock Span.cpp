#include <iostream>
#include <cstdlib>
using namespace std;
class StockSpannerOLD
{
public:
    stack<int> st;
    StockSpanner() {}

    void solve(stack<int> &st, int &span, int &topEle)
    {

        if (st.empty())
            return;

        int secondTop = st.top();
        st.pop();
        if (secondTop <= topEle)
        {
            span++;
            solve(st, span, topEle);
            st.push(secondTop);
        }
        else
        {
            st.push(secondTop);
            return;
        }
    }

    int calculateSpan(stack<int> &st)
    {
        int topEle = st.top();
        st.pop();
        int span = 1;
        if (!st.empty())
        {
            solve(st, span, topEle);
        }
        st.push(topEle);
        return span;
    }

    int next(int price)
    {

        st.push(price);
        return calculateSpan(st);
    }
};
class StockSpanner
{
public:
    stack<pair<int, int>> st;
    StockSpanner() {}

    int next(int price)
    {

        int ans = 1;
        while (!st.empty() && st.top().first <= price)
        {
            ans += st.top().second;
            st.pop();
        }
        st.push({price, ans});
        return st.top().second;
    }
};

int main()
{
    system("cls");
    return 0;
}