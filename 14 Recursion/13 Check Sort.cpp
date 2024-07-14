#include<iostream>
#include <cstdlib>
using namespace std;
bool checkSortA( int arr[], int size, int idx){
    if( idx == size || idx + 1== size){
        return true;
    }
    if( arr[idx] <= arr[idx+1]){
        return checkSortA(arr,size,idx+1);
    }else{
        return false;
    }

}
bool checkSortB( int arr[], int size, int idx){
    if( idx == size || idx + 1== size){
        return true;
    }
    if( arr[idx] >= arr[idx+1]){
        return checkSortB(arr,size,idx+1);
    }else{
        return false;
    }

}
int main()
{
    system("cls");
    int a[5]={1,2,3,4,3};
    cout<<checkSortA( a,5,0)<<endl;
    int b[5]={5,1,3,2,1};
    cout<<checkSortB( b,5,0)<<endl;

    return 0;
}