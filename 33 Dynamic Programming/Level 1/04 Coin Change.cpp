class Solution
{
public:
    // Normal Recursion
    int solve(vector<int> &coins, int amt)
    {
        if (amt == 0)
            return 0;

        int mini = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
        {
            if (coins[i] <= amt)
            {
                int recAns = solve(coins, amt - coins[i]);
                if (recAns != INT_MAX)
                {
                    recAns++;
                }
                mini = min(mini, recAns);
            }
        }
        return mini;
    }
    // Top Down
    int solveM(vector<int> &coins, int amt, vector<int> &dp)
    {
        if (amt == 0)
            return 0;
        if (dp[amt] != -1)
            return dp[amt];
        int mini = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
        {
            if (coins[i] <= amt)
            {
                int recAns = solveM(coins, amt - coins[i], dp);
                if (recAns != INT_MAX)
                {
                    recAns++;
                }
                mini = min(mini, recAns);
            }
        }
        dp[amt] = mini;
        return dp[amt];
    }
    int solveT(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (int amt = 1; amt <= amount; amt++)
        {
            int mini = INT_MAX;
            for (int i = 0; i < coins.size(); i++)
            {
                if (coins[i] <= amt)
                {
                    int recAns = dp[amt - coins[i]];
                    if (recAns != INT_MAX)
                    {
                        recAns++;
                    }
                    mini = min(mini, recAns);
                }
            }
            dp[amt] = mini;
        }
        return dp[amount];
    }
    int coinChange(vector<int> &coins, int amount)
    {

        int ans = solveT(coins, amount);
        if (ans == INT_MAX)
            return -1;
        return ans;
    }
};