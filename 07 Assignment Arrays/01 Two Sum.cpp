#include<iostream>
#include<vector>
using namespace std;
pair<int, int> twoSumBrut( vector<int> arr,int target){
    pair<int,int> ans (-1,-1);
    int n = arr.size();
    for( int i = 0 ; i < n ; i++){
        for( int j = i+1 ; j < n ; j++){
            if( arr[i]+arr[j] == target){
                ans.first = i;
                ans.second = j;
                break;
            }
        }
    }
    return ans;
}

pair<int,int> twoSumOptimal( vector<int> arr,int target ){
    int start = 0;
    int end = arr.size()-1;
    pair<int,int> ans (-1,-1);
    while (start<end)
    {
        int currentSum = arr[start] + arr[end];
        if( currentSum == target){
            ans.first = start;
            ans.second = end;
            break;
        }else if( currentSum < target ){
            start++;
        }else{
            end--;
        }
    }
    return ans;
    
}
int main()
{
    vector<int> arr={1,2,3,4,5,6};
    int target = 11;
    pair <int,int> ans = twoSumOptimal(arr,target);
    if( ans.first == -1){
        cout<<"Pair Not Found"<<endl;
    }else{
        cout<<"Pair found !!"<<endl;
        cout<<"{ "<<ans.first<<","<<ans.second<<" }"<<endl;
    }
    return 0;
}