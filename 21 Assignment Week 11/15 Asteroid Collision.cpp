class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {

        stack<int> st;

        for (auto ast : asteroids)
        {
            bool des = false;
            if (ast > 0)
            {
                st.push(ast);
            }
            else
            {
                if (st.empty())
                {
                    st.push(ast);
                }
                else
                {
                    while (!st.empty() && st.top() > 0)
                    {
                        if (abs(st.top()) == abs(ast))
                        {
                            des = true;
                            st.pop();
                            break;
                        }
                        else if (abs(ast) > abs(st.top()))
                        {
                            st.pop();
                        }
                        else
                        {
                            des = true;
                            break;
                        }
                    }
                    if (!des)
                        st.push(ast);
                }
            }
        }
        vector<int> ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};