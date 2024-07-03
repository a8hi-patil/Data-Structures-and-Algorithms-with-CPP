#include<iostream>
using namespace std;
int findUniqueNumber( int arr[], int size ){
    int ans = 0;
    for( int i =0 ; i < size ; i++){
        ans = ans^arr[i];
    }
    return ans;
}
int main()
{
    int arr [5]={10,20,10,20,50};
    int size = 5;
    int res = findUniqueNumber( arr, size);
    cout<<"The unique number is : "<<res;
    return 0;
}