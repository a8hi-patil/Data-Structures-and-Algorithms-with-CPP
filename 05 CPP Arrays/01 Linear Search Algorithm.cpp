#include<iostream>
using namespace std;
bool findTarget( int arr[],int size, int target){
    bool isTargetFound = false;
    for( int i =0 ; i < size; i++){
        if( arr[i] == target){
            isTargetFound = true;
            break;
        }
    }
    return isTargetFound;
}
int main()
{
    int arr[5]={10,20,30,40,50};
    int size = 5;
    int target = 40;
    bool res = findTarget(arr,size,target);
    if(res){
        cout<<"Target Found !";
    }else{
        cout<<"Target not found !";
    }
    cout<<endl;
    target = 48;
    res = findTarget(arr,size,target);
    if(res){
        cout<<"Target Found !";
    }else{
        cout<<"Target not found !";
    }
    return 0;
}