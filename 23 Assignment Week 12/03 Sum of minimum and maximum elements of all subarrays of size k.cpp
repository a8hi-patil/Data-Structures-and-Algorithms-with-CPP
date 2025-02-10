#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;
vector<int> findMaxInKWindow(vector<int> arr, int k)
{
    vector<int> ans;
    deque<int> q;

    for (int i = 0; i < k; i++)
    {
        if (q.empty())
        {
            q.push_front(i);
        }
        else
        {
            while (!q.empty() && arr[q.back()] < arr[i])
            {
                q.pop_back();
            }
            q.push_back(i);
        }
    }
    ans.push_back(arr[q.front()]);
    int i = k;
    while (i < arr.size())
    {
        if (i - k + 1 > q.front())
        {
            q.pop_front();
        }
        while (!q.empty() && arr[q.back()] < arr[i])
        {
            q.pop_back();
        }
        q.push_back(i);

        ans.push_back(arr[q.front()]);
        i++;
    }
    return ans;
}
vector<int> findMinInKWindow(vector<int> arr, int k)
{
    vector<int> ans;
    queue<int> q;
    for (int i = 0; i < k; i++)
    {
        if (q.empty())
        {
            q.push(i);
        }
        else
        {
            while (!q.empty() && arr[q.front()] > arr[i])
            {
                q.pop();
            }
            q.push(i);
        }
    }
    ans.push_back(arr[q.front()]);
    int i = k;
    while (i < arr.size())
    {
        // check window
        //  0 1 2 3 4
        if (i - k + 1 > q.front())
        {
            q.pop();
        }
        // add next
        while (!q.empty() && arr[q.front()] > arr[i])
        {
            q.pop();
        }
        q.push(i);
        ans.push_back(arr[q.front()]);
        i++;
    }
    return ans;
}
int main()
{
    system("cls");
    vector<int> arr = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    vector<int> smaller = findMinInKWindow(arr, k);
    vector<int> bigger = findMaxInKWindow(arr, k);
    int maxSum = 0;
    for (int i = 0; i < smaller.size(); i++)
    {
        maxSum += smaller[i] + bigger[i];
    }
    cout << maxSum;
    int output = 18;
    return 0;
}