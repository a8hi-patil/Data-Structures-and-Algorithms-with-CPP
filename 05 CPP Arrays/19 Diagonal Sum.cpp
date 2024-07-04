#include<iostream>
#include<vector>

using namespace std;
void diagonalSum( vector <vector<int>> arr){
    int row = arr.size();
    int sum = 0;
    for( int i = 0; i <row ; i++){
            sum+=arr[i][i];
        }
        cout<<"Diagonal sum : "<<sum<<endl;  
}
void diagonalSum2( vector <vector<int>> arr){
    int row = arr.size();
    int sum = 0;
    for( int i = 0; i <row ; i++){
            sum+=arr[i][row - i -1];
        }
        cout<<"Diagonal sum2 : "<<sum<<endl;  
}

int main()
{
   vector<vector<int>> arr ={{1,2,3},{4,5,6},{17,8,9}};
    int row=3;
    int col=3;
    diagonalSum(arr);
    diagonalSum2(arr);
    
    return 0;
}