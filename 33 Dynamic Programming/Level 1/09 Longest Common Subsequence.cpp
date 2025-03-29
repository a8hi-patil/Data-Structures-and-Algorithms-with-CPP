class Solution
{
public:
    int solve(string &text1, string &text2, int i, int j)
    {
        if (i >= text1.size() || j >= text2.size())
            return 0;

        int ans = 0;
        if (text1[i] == text2[j])
        {
            ans = 1 + solve(text1, text2, i + 1, j + 1);
        }
        else
        {
            ans = max(solve(text1, text2, i + 1, j),
                      solve(text1, text2, i, j + 1));
        }
        return ans;
    }
    int solveM(string &text1, string &text2, int i, int j,
               vector<vector<int>> &dp)
    {
        if (i >= text1.size() || j >= text2.size())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = 0;
        if (text1[i] == text2[j])
        {
            ans = 1 + solveM(text1, text2, i + 1, j + 1, dp);
        }
        else
        {
            ans = max(solveM(text1, text2, i + 1, j, dp),
                      solveM(text1, text2, i, j + 1, dp));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }

    int solveT(string text1, string text2)
    {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        for (int i = text1.size() - 1; i >= 0; i--)
        {
            for (int j = text2.size() - 1; j >= 0; j--)
            {
                int ans = 0;
                if (text1[i] == text2[j])
                {
                    ans = 1 + dp[i + 1][j + 1];
                }
                else
                {
                    ans = max(dp[i + 1][j], dp[i][j + 1]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        int i = 0;
        int j = 0;
        // vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size(),
        // -1));
        return solveT(text1, text2);
    }
};