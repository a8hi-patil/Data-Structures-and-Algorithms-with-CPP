#include<iostream>
#include<vector>
using namespace std;
void printArray ( vector< int> arr){
    int len = arr.size();
    for( int i = 0 ; i < len ; i++){
        cout<<arr[i]<< " ";
    }
    cout<<endl;
}
int removeDuplicates( vector<int> &arr){
    int i = 0;
    int j = i+1;
    while( j < arr.size() ){
        if( arr[i] == arr[j]){
            j++;
        }else{
            i++;
            arr[i] = arr[j];
        }
    }
    cout<<i<<endl;
    return i;
}
int main()
{
    vector<int> arr = {0,0,1,1,1,2,2,3,3,4};
    int i = removeDuplicates(arr);
    fill(arr.begin()+i+1,arr.end(),-1);
    printArray(arr);
    return 0;
}