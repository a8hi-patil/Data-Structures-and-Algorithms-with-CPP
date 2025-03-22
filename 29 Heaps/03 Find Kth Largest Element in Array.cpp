#include <iostream>
#include <cstdlib>
#include <queue>
#include <vector>
using namespace std;
int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int> greater<int>> minHeap;
    for (int i = 0; i < k; i++)
    {
        minHeap.push(nums[i]);
    }
    for (int i = k; i < nums.size(); i++)
    {
        int val = nums[i];
        if (minHeap.top() < val)
        {
            minHeap.pop();
            minHeap.push(val);
        }
    }
    return minHeap.top();
}
int main()
{
    system("cls");
    return 0;
}