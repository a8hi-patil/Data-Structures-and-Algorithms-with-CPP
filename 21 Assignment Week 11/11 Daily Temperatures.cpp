class Solution
{
public:
    void findNextGreater(vector<int> &ip, vector<int> &op)
    {
        stack<int> st;
        st.push(0);

        for (int i = ip.size() - 1; i >= 0; i--)
        {
            int ele = ip[i];

            while (!st.empty() && st.top() != 0 && ele >= ip[st.top()])
            {
                st.pop();
            }
            if (st.top())
            {
                op.push_back(st.top() - i);
            }
            else
            {
                op.push_back(st.top());
            }
            st.push(i);
        }
        reverse(op.begin(), op.end());
    }
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> nextGreater(temperatures.size(), 0);
        stack<int> st;

        for (int i = 0; i < temperatures.size(); i++)
        {
            while (!st.empty() && temperatures[i] > temperatures[st.top()])
            {
                nextGreater[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }

        return nextGreater;
    }
};