class Solution
{
public:
    int maximumScore(int a, int b, int c)
    {
        priority_queue<int> pq;
        int ans = 0;
        pq.push(a);
        pq.push(b);
        pq.push(c);

        while (pq.size() > 1)
        {
            int f = pq.top();
            pq.pop();
            int s = pq.top();
            pq.pop();

            f--;
            s--;
            ans++;
            if (f > 0)
                pq.push(f);
            if (s > 0)
                pq.push(s);
        }
        return ans;
    }
};