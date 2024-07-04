#include<iostream>
#include<vector>
using namespace std;
int MaximumSubarraySum( vector< int> arr, int k){
    int i = 0; int j = 0;
    int maxSum = INT_MIN;
    int len = arr.size();
    while( j < len ){
        int currentSum = 0;
        for( int y = i ; y <= j ; y++){
            currentSum+=arr[y];
        }
        maxSum = max(maxSum,currentSum);
        i++;
        j++;
    }
    return maxSum;
}
int slidingWindow( vector<int> arr , int k){
    int i = 0;int j = k-1; int sum = 0;
    for( int y = i ; y <= j ; y++){
            sum+=arr[y];
    }
    int len = arr.size();
    int maxSum = INT_MIN;
    j++;
    while( j < len){
        sum+=arr[j++];
        sum-=arr[i++];
        maxSum = max( maxSum, sum);
    }
    return maxSum;
}
int main()
{
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    int maxSum = slidingWindow( arr,4);
    cout<<"Maximum sum is : "<<maxSum<<endl;
    return 0;
}