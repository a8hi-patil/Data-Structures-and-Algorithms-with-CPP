#include<iostream>
#include<vector>

using namespace std;
void findRowWiseSum( vector <vector<int>> arr){
    int row = arr.size();
    int col = arr[0].size();
    for( int i = 0; i <row ; i++){
        int sum = 0;
        for( int j = 0 ; j< col; j++){
            sum+=arr[i][j];
        }
        cout<<"Row wise sum of row "<<i+1<<" is "<<sum<<endl;
    }
}
void findColWiseSum( vector <vector<int>> arr){
    int row = arr.size();
    int col = arr[0].size();
    for( int i = 0; i <col ; i++){
        int sum = 0;
        for( int j = 0 ; j< row; j++){
            sum+=arr[j][i];
        }
        cout<<"Column wise sum of column "<<i+1<<" is "<<sum<<endl;
    }
}
int main()
{
   vector<vector<int>> arr ={{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
    int row=3;
    int col=3;
    findRowWiseSum(arr);
    findColWiseSum(arr);
    
    return 0;
}