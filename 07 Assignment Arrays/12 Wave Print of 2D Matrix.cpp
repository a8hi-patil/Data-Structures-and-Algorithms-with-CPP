#include<iostream>
#include<vector>
using namespace std;
void wavePrintMatrix( vector<vector<int>> arr){
    for( int startCol = 0 ; startCol < arr.size() ; startCol++){
        if( startCol & 1){
            //odd
             for( int i =0; i < arr.size() ; i++){
                cout<<arr[arr.size()-i-1][startCol]<<" ";
            }
        }else{
            // even
            for( int i =0; i < arr.size() ; i++){
                cout<<arr[i][startCol]<<" ";
            }
        }
        cout<<endl;
    }
}
int main()
{
    vector<vector<int>> arr={{1,2,3,4},
                             {5,6,7,8},
                             {9,10,11,12},
                             {13,14,15,16}};
                             wavePrintMatrix(arr);
    return 0;
}