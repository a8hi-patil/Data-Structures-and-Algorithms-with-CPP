#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int missingNumber( vector<int> arr){
    int len = arr.size();
    sort(arr.begin(),arr.end());
    for( int i = 0 ; i < len ; i++){
        if( arr[i] != i){
        return i;
        }
    }
    return -1;
}
int missingNumber1( vector<int> arr){
    int len = arr.size();
    int ans = 0;
    for( int i = 0 ; i < len ; i++){
        ans^=arr[i];
        ans^=i;
    }
    return ans^len;
}
int main()
{
    vector<int> arr={0,1};
    int misNum = missingNumber1( arr );
    cout<<"Missing Number is "<<misNum<<endl;
    return 0;
}