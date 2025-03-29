class Solution
{
public:
    bool solve(vector<int> &nums, int target, int idx)
    {
        if (target < 0 || idx >= nums.size())
            return false;
        if (target == 0)
            return true;

        bool inc = solve(nums, target - nums[idx], idx + 1);
        bool ex = solve(nums, target, idx + 1);
        return inc || ex;
    }

    bool solveMem(vector<int> &nums, int target, int idx,
                  vector<vector<int>> &dp)
    {
        if (target < 0 || idx >= nums.size())
            return false;
        if (target == 0)
            return true;
        if (dp[target][idx] != -1)
            return dp[target][idx];

        bool inc = solveMem(nums, target - nums[idx], idx + 1, dp);
        bool ex = solveMem(nums, target, idx + 1, dp);
        dp[target][idx] = inc || ex;
        return dp[target][idx];
    }
    bool solveTab(vector<int> &nums, int target)
    {
        vector<vector<bool>> dp(target + 1, vector<bool>(nums.size() + 1, 0));
        for (int i = 0; i < nums.size(); i++)
        {
            dp[0][i] = true;
        }
        for (int newTar = 1; newTar <= target; newTar++)
        {
            for (int newIdx = nums.size() - 1; newIdx >= 0; newIdx--)
            {
                bool inc = false;
                if (newTar - nums[newIdx] >= 0)
                    inc = dp[newTar - nums[newIdx]][newIdx + 1];
                bool ex = dp[newTar][newIdx + 1];
                dp[newTar][newIdx] = inc || ex;
            }
        }
        return dp[target][0];
    }
    bool canPartition(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2)
            return false;
        int target = sum >> 1;
        int idx = 0;
        // vector<vector<int>> dp(target + 1, vector<int>(nums.size() + 1, -1));
        return solveTab(nums, target);
    }
};