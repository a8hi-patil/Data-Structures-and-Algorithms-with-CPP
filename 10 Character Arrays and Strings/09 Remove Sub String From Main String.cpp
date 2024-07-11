#include<iostream>
using namespace std;

string removeSubString( string str, string subStr){
 while (str.find(subStr) != string::npos)
 {
    str.erase( str.find(subStr),subStr.length());
 }
 
return str;
}

int main()
{
    string s = "daabcbaabcbc", part = "abc";
    string ans = removeSubString(s,part);
    cout<<"Ans is "<<ans;   
    return 0;
}