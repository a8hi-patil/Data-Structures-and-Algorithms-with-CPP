class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];

            if (!st.empty() && ch == ')' && st.top() == '(')
                st.pop();
            else
                st.push(ch);
        }
        return st.size();
    }
};