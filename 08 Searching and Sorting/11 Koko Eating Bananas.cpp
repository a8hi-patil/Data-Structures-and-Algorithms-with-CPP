#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
bool canKokoEatBananas(vector<int> arr, int h, int mid ){
    int totalHours = 0;
    for( int i = 0 ; i<arr.size(); i++){
        totalHours+= ceil(arr[i]/double(mid));
    }
    return totalHours <= h;
}
int findMinimumNumberOfBananas( vector<int> arr, int h){
    int start = 1;
    int end = *max_element( arr.begin(),arr.end());
    int mid = start + ( end - start)/2;
    int ans= -1;
    while( start <= end){
        if( canKokoEatBananas( arr, h,mid)){
            ans = mid;
            end = mid-1;
        }else{
            start =mid+1;
        }
        mid = start + ( end - start)/2;
    }
    return ans;
}
int main()
{
   vector< int> arr={3,6,7,11};
   int h = 8;
   cout<<"Koko can eat all bananas in "<<h<<" hours if she eats "<<findMinimumNumberOfBananas(arr,h)<<" bananas per hour."<<endl;
    return 0;
}