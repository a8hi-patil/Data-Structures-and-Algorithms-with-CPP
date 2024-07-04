#include<iostream>
#include<vector>
#include <unordered_map> 
using namespace std;
int findFirstRepeatingElement( vector<int> arr ){
    int len = arr.size();
    for( int i = 0 ; i < len ; i++){
        for( int j = i + 1; j < len ; j++){
            if( arr[i] == arr[j]){
                return arr[i];
            }
        }
    }
    return -1;
} 
int usingUnorderedHash( vector<int> arr){
    unordered_map<int,int> hash;
    for( int i = 0 ; i < arr.size() ; i++){
        hash[arr[i]] = hash[arr[i]] + 1;
    }
    for( int i = 0 ; i < arr.size() ; i++){
        if(hash[arr[i]] > 1)
        return arr[i]; 
    }
    return -1;
}
int main()
{
    vector<int> arr={1,5,3,4,3,5,6};
    int repeatedElement = findFirstRepeatingElement( arr);
    cout<<"First repeating element : "<< repeatedElement<<endl;
    int repeatedElement1 = usingUnorderedHash( arr);
    cout<<"First repeating element : "<< repeatedElement1<<endl;
    return 0;
}