#include<iostream>
#include<unordered_map>
using namespace std;

int findSingleNumber( int arr[], int size){
    unordered_map<int,int> ans;
    for( int i = 0 ; i < size ; i++){
      int num = arr[i];
      ans[num] = ans[num] +1;
    }

    unordered_map<int,int> :: iterator it;
    int val = -1;
    for( it = ans.begin() ; it != ans.end() ; it++){
        if( it->second == 1){
            val = it->first;
            break;
        }
    }
    return val;
}
int main()
{
    int arr[5]={4,1,2,1,2};
    int size = 5;
    int singleNumber = findSingleNumber( arr, size );
    cout<<"Single Number in Array is "<<singleNumber<<endl ;
    return 0;
}