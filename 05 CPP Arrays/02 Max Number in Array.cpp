#include<iostream>
using namespace std;
int findMaxNumber( int arr[], int size){
    int maxNumber = INT_MIN;
    for( int i = 0 ; i < size; i++){
        maxNumber = max(maxNumber,arr[i]);
    }
    return maxNumber;
}
int main()
{
    int arr[5]={10,20,300,40,50};
    int size = 5;
    int maxNumber = findMaxNumber( arr,size);
    cout<<"Max number is "<<maxNumber;
    return 0;
}