class Solution
{
public:
    int findTheWinner(int n, int k)
    {
        queue<int> q;
        for (int i = 1; i <= n; i++)
        {
            q.push(i);
        }
        while (q.size() != 1)
        {

            int n = k;
            for (int i = 0; i < n - 1; i++)
            {
                q.push(q.front());
                q.pop();
            }
            q.pop();
        }
        return q.front();
    }
    int findTheWinner2(int N, int k)
    {
        int i = 1, ans = 0;
        while (i <= N)
        {
            ans = (ans + k) % i;
            i++;
        }
        return ans + 1;
    }
};