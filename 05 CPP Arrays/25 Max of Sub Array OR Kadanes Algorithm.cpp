#include<iostream>
using namespace std;

int kadanesAlgorithm( int arr[] ,int size){
    int sum = 0;
    int maxSum = arr[0];
    for( int i = 0; i < size ; i++){
        sum = sum + arr[i];
        maxSum = max( maxSum,sum);
        if( sum < 0 ){
            sum = 0;
        }
    }
    return maxSum;
}
int main()
{
    int arr[9]={-2,1,-3,4,-1,2,1,-5,4};
    int maxSubArraySum = kadanesAlgorithm(arr,9);
    cout<<"Max sub array sum is "<<maxSubArraySum<<endl;
    return 0;
}