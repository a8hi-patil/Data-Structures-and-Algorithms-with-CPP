class Solution
{
public:
    int solve(vector<int> &nums, int i, vector<int> &dp)
    {
        if (i >= nums.size())
        {
            return 0;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }
        int include = nums[i] + solve(nums, i + 2, dp);
        int exclude = 0 + solve(nums, i + 1, dp);
        int maxAns = max(include, exclude);
        dp[i] = maxAns;
        return dp[i];
    }
    int solveTab(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 2, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            int include = nums[i] + dp[i + 2];
            int exclude = 0 + dp[i + 1];
            int maxAns = max(include, exclude);
        }

               return dp[0];
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        int i = 0;
        return solve(nums, i, dp);
    }
};