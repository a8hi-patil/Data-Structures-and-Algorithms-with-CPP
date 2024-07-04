#include<iostream>
#include<vector>
using namespace std;
int findPivoteIndex( vector<int> arr){
    vector<int> lsum(arr.size(),0);
    vector<int> rsum(arr.size(),0);
    int end = arr.size();

    for( int i = 1 ; i < end ; i++){
        lsum[i] = arr[i-1] + lsum[i-1];
        }

    for( int j = end -2 ; j >= 0 ; j--){
        rsum[j] = arr[j+1] + rsum[j+1];
    }

    for( int k = 0 ; k<end ; k++){
        if( lsum[k] == rsum[k]){
            return k;
        }
    }
    return -1;
}
int main()
{
    vector<int> arr={1,7,3,6,5,6};
    int ans = findPivoteIndex(arr);
    cout<<"Pivot Index is "<<ans<<endl;
    
    return 0;
}