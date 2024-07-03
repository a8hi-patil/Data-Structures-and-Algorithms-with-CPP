#include<iostream>
using namespace std;
void printAllPairsOfArray( int arr[], int size){
    for( int i = 0; i < size; i++){
        for( int j = 0 ; j < size ; j++){
            cout<<"{"<<arr[i]<<" "<<arr[j]<<"}, ";
        }
        cout<<endl;
    }
}
int main()
{
    int arr[5]={10,20,30,40,50};
    int size=5;
    printAllPairsOfArray(arr,size);    
    return 0;
}