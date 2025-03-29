class Solution
{
public:
    // recursion
    int solve(int i, vector<int> &nums)
    {
        if (i >= nums.size())
            return 0;
        int inc = nums[i] + solve(i + 2, nums);
        int ex = solve(i + 1, nums);
        return max(inc, ex);
    }
    // top-down
    int solveMem(int i, vector<int> &nums, vector<int> &dp)
    {
        if (i >= nums.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int inc = nums[i] + solveMem(i + 2, nums, dp);
        int ex = solveMem(i + 1, nums, dp);
        dp[i] = max(inc, ex);
        return dp[i];
    }
    // bottom up
    int solveTab(int i, vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 20, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            int inc = nums[i] + dp[i + 2];
            int ex = dp[i + 1];
            dp[i] = max(inc, ex);
        }
        return dp[0];
    }
    // bottom up Space Optimised
    int solveTabSO(vector<int> &nums)
    {
        int n1 = 0;
        int n2 = 0;

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            int inc = nums[i] + n2;
            int ex = n1;
            int curr = max(inc, ex);
            n2 = n1;
            n1 = curr;
        }
        return n1;
    }
    int rob(vector<int> &nums) { return solveTabSO(nums); }
};