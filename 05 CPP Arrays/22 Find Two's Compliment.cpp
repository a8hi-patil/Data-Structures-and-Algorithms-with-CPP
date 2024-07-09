#include<iostream>
#include<vector>
using namespace std;
void printArray( vector<int> arr){

    int size = arr.size();
    for( int i = 0 ; i < size ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void onesCompliment( vector<int> &arr,vector<int> &arr2){
    for( int i = 0 ; i<arr.size() ; i++){
        arr2[i+1] = arr[i] == 0 ? 1 : 0;
    }
}
void twosCompliment( vector<int> &arr ){
    int carry = 1;
    for( int i = arr.size()-1 ; i >= 0 ; i--){
        int sum = arr[i] + carry;
        arr[i] = sum %2;
        carry = sum/2;
        

    }
}
int main()
{
        vector<int> arr={1,1,0,0};
        vector<int> twosComp(arr.size()+1,0);
        onesCompliment(arr,twosComp);
        printArray(twosComp);
        twosCompliment(twosComp);
        printArray(twosComp);
    return 0;
}