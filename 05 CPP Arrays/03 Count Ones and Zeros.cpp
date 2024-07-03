#include<iostream>
using namespace std;

void countOnesAndZeros( int arr[],int size){
    int countOfZero = 0;
    int countOfOne = 0;
    for( int i = 0 ; i < size ; i++){
        if( arr[i]==0){
            countOfZero++;
        }else{
            countOfOne++;
        }
    }
    cout<<"Count of zero's are "<<countOfZero<<endl;
    cout<<"Count of ones's are "<<countOfOne<<endl;
}
int main()
{
    int arr[5]={1,0,1,0,1};
    int size = 5;
    countOnesAndZeros(arr,size);
    return 0;
}