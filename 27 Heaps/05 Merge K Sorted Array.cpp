//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

// } Driver Code Ends
// User function Template for C++
class Info
{
public:
    int data;
    int rIndex;
    int cIndex;

    Info(int data, int x, int y)
    {
        this->data = data;
        this->rIndex = x;
        this->cIndex = y;
    }
};

class compare
{
public:
    bool operator()(Info *a, Info *b)
    {

        return a->data > b->data;
    }
};

class Solution
{
public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<Info *, vector<Info *>, compare> pq;
        vector<int> ans;
        int totalCols = arr[0].size();
        for (int i = 0; i < arr.size(); i++)
        {
            int ele = arr[i][0];
            Info *temp = new Info(ele, i, 0);
            pq.push(temp);
        }

        while (!pq.empty())
        {
            auto front = pq.top();
            pq.pop();
            int front_rowIdx = front->rIndex;
            int front_colIdx = front->cIndex;
            ans.push_back(front->data);
            if (front_colIdx + 1 < totalCols)
            {
                Info *temp = new Info(arr[front_rowIdx][front_colIdx + 1], front_rowIdx, front_colIdx + 1);
                pq.push(temp);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        vector<vector<int>> arr(k, vector<int>(k, 0));
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                cin >> arr[i][j];
            }
        }
        Solution obj;
        vector<int> output = obj.mergeKArrays(arr, k);
        printArray(output, k * k);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends