class Solution
{
public:
    int memoisation(int n, vector<int> &dp)
    {
        if (n == 0 || n == 1)
        {
            return n;
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }
        dp[n] = memoisation(n - 1, dp) + memoisation(n - 2, dp);
        return dp[n];
    }
    int bottomUp(int n)
    {
        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        if (n == 0)
        {
            return 0;
        }
        dp[1] = 1;

        for (int i = 2; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];

        return dp[n];
    }
    int bottomUpSpaceOprtimised(int n)
    {
        if (n == 0 || n == 1)
        {
            return n;
        }
        int prev = 0;
        int curr = 1;

        for (int i = 2; i <= n; i++)
        {
            int ans = prev + curr;
            prev = curr;
            curr = ans;
        }

        return ans;
    }
    int fib(int n)
    {
        vector<int> dp(n + 1, -1);
        return memoisation(n, dp);
        return bottomUp(n);
    }
};