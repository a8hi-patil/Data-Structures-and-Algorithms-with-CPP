class Solution
{
public:
    // Pure Recursion
    int solve(int n)
    {
        if (n == 0 || n == 1)
            return n;
        return solve(n - 1) + solve(n - 2);
    }
    // Top Down Approach
    int solveWith(int n, vector<int> &dp)
    {
        if (n == 0 || n == 1)
            return n;
        if (dp[n] != -1)
            return dp[n];
        dp[n] = solveWith(n - 1, dp) + solveWith(n - 2, dp);
        return dp[n];
    }
    // Bottom Up Approah
    int solveWithTab(int n)
    {
        if (n == 0 || n == 1)
            return n;
        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
    // Space optimasation
    int solveWithTabSpaceOptimised(int n)
    {
        if (n == 0 || n == 1)
            return n;

        int prev2 = 0;
        int prev1 = 1;
        for (int i = 2; i <= n; i++)
        {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    int fib(int n) { return solveWithTabSpaceOptimised(n); }
};