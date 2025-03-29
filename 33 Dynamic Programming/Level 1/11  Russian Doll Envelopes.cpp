
class Solution
{
public:
    bool canfit(vector<int> &a, vector<int> &b)
    {
        if (a[0] > b[0] && a[1] > b[1])
            return true;
        return false;
    }
    int solve(vector<vector<int>> &envelopes, int curr, int prev)
    {

        if (curr >= envelopes.size())
            return 0;

        int in = 0;
        if (prev == -1 || canfit(envelopes[curr], envelopes[prev]))
        {
            in = 1 + solve(envelopes, curr + 1, curr);
        }
        int ex = solve(envelopes, curr + 1, prev);
        return max(in, ex);
    }
    int solveM(vector<vector<int>> &envelopes, int curr, int prev,
               vector<vector<int>> &dp)
    {

        if (curr >= envelopes.size())
            return 0;
        if (dp[curr][prev + 1] != -1)
            return dp[curr][prev + 1];
        int in = 0;
        if (prev == -1 || canfit(envelopes[curr], envelopes[prev]))
        {
            in = 1 + solveM(envelopes, curr + 1, curr, dp);
        }
        int ex = solveM(envelopes, curr + 1, prev, dp);
        dp[curr][prev + 1] = max(in, ex);
        return dp[curr][prev + 1];
    }
    int solveT(vector<vector<int>> &envelopes)
    {
        vector<vector<int>> dp(envelopes.size() + 1,
                               vector<int>(envelopes.size() + 1, 0));

        for (int curr = envelopes.size() - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {
                int in = 0;
                if (prev == -1 || canfit(envelopes[curr], envelopes[prev]))
                {
                    in = 1 + dp[curr + 1][curr + 1];
                }
                int ex = dp[curr + 1][prev + 1];
                dp[curr][prev + 1] = max(in, ex);
            }
        }
        return dp[0][0];
    }
    int solveTSO(vector<vector<int>> &envelopes)
    {

        vector<int> prevRow(envelopes.size() + 1, 0);
        vector<int> currRow(envelopes.size() + 1, 0);
        for (int curr = envelopes.size() - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {
                int in = 0;
                if (prev == -1 || canfit(envelopes[curr], envelopes[prev]))
                {
                    in = 1 + prevRow[curr + 1];
                }
                int ex = prevRow[prev + 1];
                currRow[prev + 1] = max(in, ex);
            }
            prevRow = currRow;
        }
        return prevRow[0];
    }
    int solveTSO2(vector<vector<int>> &envelopes)
    {

        // vector<int> prevRow(envelopes.size() + 1, 0);
        vector<int> currRow(envelopes.size() + 1, 0);
        for (int curr = envelopes.size() - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {
                int in = 0;
                if (prev == -1 || canfit(envelopes[curr], envelopes[prev]))
                {
                    in = 1 + currRow[curr + 1];
                }
                int ex = currRow[prev + 1];
                currRow[prev + 1] = max(in, ex);
            }
        }
        return currRow[0];
    }
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {

        sort(envelopes.begin(), envelopes.end());
        int curr = 0;
        int prev = -1;
        // return solve(envelopes, curr, prev);

        return solveTSO2(envelopes);
    }
};