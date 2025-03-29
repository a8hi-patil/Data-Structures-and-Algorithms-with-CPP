class Solution
{
public:
    int mod = 1000000007;
    int solve(int n, int k, int t)
    {
        if (t < 0)
            return 0;
        if (n == 0 && t == 0)
            return 1;
        if (n == 0 && t != 0)
            return 0;
        if (n != 0 && t == 0)
            return 0;

        int ans = 0;
        for (int i = 1; i <= k; i++)
        {
            ans += solve(n - 1, k, t - i);
        }
        return ans;
    }
    int solveM(int n, int k, int t, vector<vector<int>> &dp)
    {
        if (t < 0)
            return 0;
        if (n == 0 && t == 0)
            return 1;
        if (n == 0 && t != 0)
            return 0;
        if (n != 0 && t == 0)
            return 0;
        if (dp[n][t] != -1)
            return dp[n][t] % mod;
        long long ans = 0;
        for (int i = 1; i <= k; i++)
        {
            ans += solveM(n - 1, k, t - i, dp) % mod;
        }
        dp[n][t] = ans % mod;
        return dp[n][t] % mod;
    }
    int numRollsToTarget(int n, int k, int target)
    {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return solveM(n, k, target, dp) % mod;
    }
};