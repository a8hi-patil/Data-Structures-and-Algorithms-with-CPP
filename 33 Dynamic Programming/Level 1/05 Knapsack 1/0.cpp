class Solution
{
public:
    // Recursion
    int solve(int W, vector<int> &val, vector<int> &wt, int idx)
    {
        if (idx == 0)
        {
            if (wt[0] <= W)
            {
                return val[0];
            }
            else
            {
                return 0;
            }
        }

        int inc = 0;
        if (W >= wt[idx])
        {
            inc = val[idx] + solve(W - wt[idx], val, wt, idx - 1);
        }
        int ex = solve(W, val, wt, idx - 1);
        return max(inc, ex);
    }
    // Top Down

    int solveMem(int W, vector<int> &val, vector<int> &wt, int idx, vector<vector<int>> &dp)
    {

        if (idx == 0)
        {
            if (W >= wt[0])
            {
                return val[0];
            }
            else
            {
                return 0;
            }
        }
        if (dp[W][idx] != -1)
            return dp[W][idx];

        int inc = 0;
        if (W >= wt[idx])
        {
            inc = val[idx] + solveMem(W - wt[idx], val, wt, idx - 1, dp);
        }
        int ex = solveMem(W, val, wt, idx - 1, dp);
        dp[W][idx] = max(inc, ex);
        return dp[W][idx];
    }

    // bottom up approach

    int solveTab(int W, vector<int> &val, vector<int> &wt)
    {
        int n = val.size() - 1;
        vector<vector<int>> dp(W + 1, vector<int>(n + 1, 0));

        for (int i = wt[0]; i <= W; i++)
        {
            if (i <= W)
            {
                dp[i][0] = val[0];
            }
        }

        for (int cap = 0; cap <= W; cap++)
        {
            for (int idx = 1; idx <= n; idx++)
            {

                int inc = 0;
                if (wt[idx] <= cap)
                {
                    inc = val[idx] + dp[cap - wt[idx]][idx - 1];
                }
                int ex = dp[cap][idx - 1];

                dp[cap][idx] = max(inc, ex);
            }
        }
        return dp[W][n];
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {
        int idx = wt.size() - 1;
        return solve(W, val, wt, idx);
    }
};