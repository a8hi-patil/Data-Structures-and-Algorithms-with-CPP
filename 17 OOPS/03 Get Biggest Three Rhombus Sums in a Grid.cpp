class Solution
{
public:
    void makeRH(vector<vector<int>> &grid, int row, int col,
                priority_queue<int> &pq)
    {
        pq.push(grid[row][col]);
        int exp = 1;
        while (row - exp >= 0 && row + exp < grid.size() && col - exp >= 0 &&
               col + exp < grid[0].size())
        {
            // can make valid RH;
            pair<int, int> A = {row - exp, col};
            pair<int, int> B = {row, col + exp};
            pair<int, int> C = {row + exp, col};
            pair<int, int> D = {row, col - exp};
            int cSum = grid[A.first][A.second] + grid[B.first][B.second] +
                       grid[C.first][C.second] + grid[D.first][D.second];

            // AB
            //  0,2 <- 1,3  ->   2,4
            for (int i = 1; i < B.second - A.second; i++)
            {
                cSum += grid[A.first + i][A.second + i];
            }
            // BC
            // 2,4   <- -> 4,2
            for (int i = 1; i < B.second - C.second; i++)
            {
                cSum += grid[B.first + i][B.second - i];
            }
            // CD
            // 4,2  <- -> 2,0
            for (int i = 1; i < C.second - D.second; i++)
            {
                cSum += grid[C.first - i][C.second - i];
            }
            // DA
            // 2,0 < - -> 0,2
            for (int i = 1; i < A.second - D.second; i++)
            {
                cSum += grid[D.first - i][D.second + i];
            }
            pq.push(cSum);
            exp++;
        }
    }
    bool canPush(vector<int> &ans, int el)
    {
        for (auto a : ans)
        {
            if (el == a)
                return false;
        }
        return true;
    }
    vector<int> getBiggestThree(vector<vector<int>> &grid)
    {
        vector<int> ans;
        priority_queue<int> pq;
        int row = grid.size();
        int col = grid[0].size();

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                makeRH(grid, i, j, pq);
            }
        }
        while (!pq.empty() && ans.size() < 3)
        {
            int top = pq.top();
            pq.pop();
            if (canPush(ans, top))
            {
                ans.push_back(top);
            }
        }
        return ans;
    }
};