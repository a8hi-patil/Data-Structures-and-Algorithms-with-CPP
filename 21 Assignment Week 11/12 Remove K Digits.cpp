class Solution
{
public:
    string removeKdigits(string num, int k)
    {

        stack<char> st;

        for (auto ch : num)
        {
            if (k > 0)
            {
                while (!st.empty() && st.top() > ch)
                {
                    st.pop();
                    k--;
                    if (k == 0)
                        break;
                }
            }
            st.push(ch);
        }

        if (k > 0)
        {
            while (!st.empty() && k)
            {
                st.pop();
                k--;
            }
        }
        string ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        while (ans.size() > 0 && ans.back() == '0')
            ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans != "" ? ans : "0";
    }
};