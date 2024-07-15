#include<iostream>
#include <cstdlib>
#include<vector>
using namespace std;
void mergeTwoArrays( vector<int> a, vector<int>b , vector<int> &ans){
    int i = 0 ,j=0;
    while (i < a.size() && j < a.size())
    {
        if( a[i] < b[j]){
            ans.push_back(a[i++]);
        }else{
            ans.push_back(b[j++]);
        }
    }
    
        while (i < a.size())
        {
            ans.push_back( a[i++]);
        }
        
    
         while (j < b.size())
        {
            ans.push_back( b[j++]);
        }
        
    
    
}
int main()
{
    system("cls");
    vector<int> a ={ 20,40,60,80,90,100};
    vector<int> b ={ 10,30,50,70};
    vector<int> ans;
    mergeTwoArrays( a, b,ans);
    for( auto num : ans){
        cout<<num<<" ";
    }
    return 0;
}