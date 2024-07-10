#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool canWeMakeBouquets(vector<int>& bloomDay, int m, int k,int day){
    int counter =0;
    for( int i = 0 ; i < bloomDay.size() ; i++){
        if( bloomDay[i]<=day){
            counter++;
        }
        if( bloomDay[i] > day){
            counter =0;
        }
        if( counter == k){
            m--;
            counter =0;
        }
        if( m == 0){
            break;
        }
    }
    return m == 0;
}
int minDays(vector<int>& bloomDay, int m, int k) {

    long long int req = (long long int )m * k;
    if( req > bloomDay.size()) return -1;

    int start = *min_element(bloomDay.begin(),bloomDay.end());
    int end = *max_element(bloomDay.begin(),bloomDay.end());
    int mid = start + ( end - start) /2;
    int ans =-1;
    while( start <= end){
        if ( canWeMakeBouquets(bloomDay,m,k,mid))
        {
            ans = mid;
            end = mid-1;
        }else{
            start = mid + 1;
        }
        mid = start + ( end - start) /2;
    }
        return ans;
    }


int main()
{
    vector<int> arr={1,10,3,10,2};
    int m = 3, k = 1;
    cout<<minDays(arr,m,k);
    return 0;
}