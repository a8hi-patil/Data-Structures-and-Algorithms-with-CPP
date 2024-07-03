#include<iostream>
using namespace std;
pair<int,int> twoSum( int arr[],int size, int target){
    pair<int,int> ans (-1,-1);
    for( int i = 0 ; i < size ; i++){
        for( int j = 0 ; j < size ; j++){
            if( target == arr[i] + arr[j]){
                ans.first = i;
                ans.second = j;
                return ans;
            }
        }
    }
    return ans;
}
int main()
{
    int arr[5] = {10,20,30,40,50};
    int size = 5;
    int target = 90;
    pair<int, int> ans (-1,-1);
    ans = twoSum(arr,size,target);
    if( ans.first == -1){
        cout<<"Pair not found which adds up to target";
    }else{
        cout<<"Pair found !!"<<endl;
        cout<<"Indices are "<<ans.first<<" and "<<ans.second<<endl;
        cout<<"Values "<<arr[ans.first]<<" and "<<arr[ans.second]<<" = "<<target<<endl;
    }
    return 0;
}