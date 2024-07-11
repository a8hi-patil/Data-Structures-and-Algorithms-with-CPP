#include<iostream>
#include<vector>
using namespace std;

int calculateOnesInString( string s){
    int count=0;
    for( int i = 0; i < s.length() ; i++){
        if( s[i] == '1'){
            count++;
        }
    }
    return count;
}

void calculateNumOfDevices( vector<string> bank , vector<int> &numOfDevices){
    for( int i = 0; i < bank.size() ; i++){
        int ans = calculateOnesInString(bank[i]);
        if( ans != 0){
        numOfDevices.push_back(ans);
        }
    }
}

int calculateAdjacentProduct( vector<int> &numOfDevices){
    int product = 0;
    if(numOfDevices.size()){
    for( int i = 0 ; i < numOfDevices.size() -1 ; i++){
        product = product + numOfDevices[i] * numOfDevices[i+1];
    }
    }
    return product;
}
void printArray ( vector<int> a){
   
    
     for( int i = 0 ; i < a.size()  ; i++){
        cout<<a[i]<<" " ;
    }
}
int main()
{
    vector<string> bank ={"0"};
    vector<int> numOfDevices;
    calculateNumOfDevices(bank,numOfDevices);
    int ans = calculateAdjacentProduct(numOfDevices);
    cout<<"Number of beams "<<ans<<" !"<<endl; 
    printArray(numOfDevices);
    return 0;
}