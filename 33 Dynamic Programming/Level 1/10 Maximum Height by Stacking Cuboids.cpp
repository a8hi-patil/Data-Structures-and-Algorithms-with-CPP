class Solution
{
public:
    bool isSafe(vector<int> &a, vector<int> &b)
    {
        if (a[0] <= b[0] && a[1] <= b[1] && a[2] <= b[2])
            return true;
        return false;
    }
    int solve(vector<vector<int>> &cuboids, int prev, int curr)
    {
        if (curr >= cuboids.size())
            return 0;

        int inc = 0;

        if (prev == -1 || isSafe(cuboids[prev], cuboids[curr]))
        {
            inc = cuboids[curr][2] + solve(cuboids, curr, curr + 1);
        }
        int ex = solve(cuboids, prev, curr + 1);
        return max(inc, ex);
    }
    int solveM(vector<vector<int>> &cuboids, int prev, int curr,
               vector<vector<int>> &dp)
    {
        if (curr >= cuboids.size())
            return 0;

        if (dp[prev + 1][curr] != -1)
            return dp[prev + 1][curr];
        int inc = 0;

        if (prev == -1 || isSafe(cuboids[prev], cuboids[curr]))
        {
            inc = cuboids[curr][2] + solveM(cuboids, curr, curr + 1, dp);
        }
        int ex = solveM(cuboids, prev, curr + 1, dp);
        dp[prev + 1][curr] = max(inc, ex);
        return dp[prev + 1][curr];
    }
    int maxHeight(vector<vector<int>> &cuboids)
    {

        for (auto &el : cuboids)
        {
            sort(el.begin(), el.end());
        }
        sort(cuboids.begin(), cuboids.end());
        int prev = -1;
        int curr = 0;
        vector<vector<int>> dp(cuboids.size() + 1,
                               vector<int>(cuboids.size() + 1, -1));
        return solveM(cuboids, prev, curr, dp);
    }
};