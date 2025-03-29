class Solution
{
public:
    bool isSafe(vector<vector<int>> &image, int sr, int sc, int ch)
    {

        int n = image.size();
        int m = image[0].size();
        return (sr >= 0 && sr < n && sc >= 0 && sc < m && image[sr][sc] == ch);
    }
    void solve(vector<vector<int>> &image, int sr, int sc, int color)
    {
        cout << sr << " " << sc << endl;
        int currCh = image[sr][sc];
        if (currCh == color)
            return;
        image[sr][sc] = color;
        if (isSafe(image, sr, sc + 1, currCh))
        {
            solve(image, sr, sc + 1, color);
        }
        if (isSafe(image, sr, sc - 1, currCh))
        {
            solve(image, sr, sc - 1, color);
        }
        if (isSafe(image, sr + 1, sc, currCh))
        {
            solve(image, sr + 1, sc, color);
        }
        if (isSafe(image, sr - 1, sc, currCh))
        {
            solve(image, sr - 1, sc, color);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                  int color)
    {
        solve(image, sr, sc, color);
        return image;
    }
};