class Solution
{
public:
    int peopleAwareOfSecret(int n, int delay, int forget)
    {
        int M = 1e9 + 7;
        queue<pair<int, int>> delayQ, forgetQ;
        int ans = 1;
        int cur = 0;
        delayQ.push({1, 1});
        forgetQ.push({1, 1});
        for (int i = 1; i <= n; i++)
        {

            if (!forgetQ.empty() && forgetQ.front().first + forget <= i)
            {
                ans = (ans - forgetQ.front().second + M) % M;
                cur = (cur - forgetQ.front().second + M) % M;
                forgetQ.pop();
            }

            if (!delayQ.empty() && delayQ.front().first + delay <= i)
            {

                // ans += delayQ.front().second;
                cur = (cur + delayQ.front().second) % M;
                delayQ.pop();
            }
            if (cur > 0)
            {
                ans = (ans + cur) % M;
                delayQ.push({i, cur});
                forgetQ.push({i, cur});
            }
        }
        return ans;
    }
};