#include<iostream>
#include <cstdlib>
using namespace std;
void mergArrays( int arr[],int s,int e){
    int mid = s+ (e-s)/2;
    int leftArrLen = mid -s +1;
    int rigthArrLen = e - mid;

    int *leftArr = new int[leftArrLen];
    int *rigthArr = new int[rigthArrLen];

    int idx = s;
    for (int i = 0; i < leftArrLen; i++)
    {
        leftArr[i] = arr[idx++];
    }
    for (int i = 0; i < rigthArrLen; i++)
    {
        rigthArr[i] = arr[idx++];
    }
    
    int i = 0,j=0;
    int mainIndexArray = s;
    while ( i < leftArrLen && j < rigthArrLen)
    {
        if( leftArr[i] < rigthArr[j] ){
                arr[mainIndexArray++] = leftArr[i];
                i++;
        }else{
             arr[mainIndexArray++] = rigthArr[j];
                j++;
        }
    }
    while (i < leftArrLen)
    {
        arr[mainIndexArray++] = leftArr[i];
        i++;
    }
    while (j < rigthArrLen)
    {
        arr[mainIndexArray++] = rigthArr[j];
        j++;
    }

    delete [] leftArr;
    delete [] rigthArr;
    
}
void mergSort( int arr[],int s, int e){
    int mid = s + ( e-s )/2;
    if( s >= e){
        return;
    }
    mergSort( arr,s,mid);
    mergSort( arr,mid+1,e);
    mergArrays( arr,s,e);
}
int main()
{
    system("cls");
    int arr[5] = {3,2,4,1,5};
    int size = 5;
    int start = 0;
    int end = size -1;

    cout<<"Before Sorting"<<endl;

    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    mergSort(arr,start,end);
    cout<<"After Sorting"<<endl;

    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    
    return 0;
}