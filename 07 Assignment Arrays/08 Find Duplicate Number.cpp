#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int findDuplicateNumberSortMethod( vector<int> arr){
    sort(arr.begin(), arr.end());
    for( int i = 0 ; i<arr.size(); i++){
        if(arr[i]==arr[i+1])
        return arr[i];
    }
    return -1;

}
int findDuplicateByNegativeMarkingMethod( vector<int> arr){
    int ans= -1;
    for( int i = 0 ; i < arr.size() ; i++){
        int idx = abs(arr[i]);
        if( arr[idx] < 0 ){
            return idx;
        }else{
            arr[idx]*=-1;
        }
    }
    return ans;
}
int findDuplicateByPosMethod( vector<int> arr){
    while(arr[0] != arr[arr[0]]){
        swap(arr[0],arr[arr[0]]);
    }
    return arr[0];
}
int main()
{
    vector<int> arr={0,1,3,4,2,4,5};
    int duplicateNum = findDuplicateNumberSortMethod(arr);
    cout<<"Duplicate Number : "<<duplicateNum<<endl;
    int duplicateNum2 = findDuplicateByNegativeMarkingMethod(arr);
    cout<<"Duplicate Number : "<<duplicateNum2<<endl;
    int duplicateNum3 = findDuplicateByPosMethod(arr);
    cout<<"Duplicate Number : "<<duplicateNum3<<endl;
    return 0;
}