#include<iostream>
#include <cstdlib>
using namespace std;
void printSubSequent( string s, int idx, string output){
    if( idx == s.length()){
        cout<<output<<endl;
        return;
    }
    printSubSequent(s,idx+1,output+s[idx]);
    printSubSequent(s,idx+1,output);
}
int main()
{
    system("cls");
    string s ="abc";
    string output = "";
    printSubSequent(s,0,output);
    return 0;
}