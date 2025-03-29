class Solution
{
public:
    // Recursion
    int solve(vector<int> &arr, int lastIdx, int i)
    {
        if (i >= arr.size())
            return 0;

        int inc = 0;
        if (lastIdx == -1 || arr[i] > arr[lastIdx])
        {
            inc = 1 + solve(arr, i, i + 1);
        }
        int ex = solve(arr, lastIdx, i + 1);
        return max(inc, ex);
    }
    // top - bottom
    int solveMem(vector<int> &arr, int lastIdx, int i,
                 vector<vector<int>> &dp)
    {
        if (i >= arr.size())
            return 0;
        if (dp[lastIdx + 1][i] != -1)
            return dp[lastIdx + 1][i];
        int inc = 0;
        if (lastIdx == -1 || arr[i] > arr[lastIdx])
        {
            inc = 1 + solveMem(arr, i, i + 1, dp);
        }
        int ex = solveMem(arr, lastIdx, i + 1, dp);
        dp[lastIdx + 1][i] = max(inc, ex);
        return dp[lastIdx + 1][i];
    }

    int lengthOfLIS(vector<int> &nums)
    {
        int i = 0;
        int lastIdx = -1;
        vector<vector<int>> dp(nums.size() + 1,
                               vector<int>(nums.size() + 1, -1));
        return solveMem(nums, lastIdx, i, dp);
    }
};