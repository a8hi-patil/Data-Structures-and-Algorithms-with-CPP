#include<iostream>
#include <cstdlib>
#include<string>
#include<bits/stdc++.h>
using namespace std;
void reverserTheWordsOfString( string &s){
    int start = 0; int end = 0;
    reverse(s.begin(),s.end());

    for( int i = 0 ; i < s.length() ; i++){
        while (s[i] == ' ' && i < s.length())
        {
            i++;
        }
        if( i == s.length()) break;
        while (s[i] != ' ' && i < s.length())
        {
            s[end++] = s[i++];
        }
        reverse(s.begin()+start,s.begin()+end);
        s[end++]=' ';
        start = end;
        
    }
    s.resize(end-1);
}
int main()
{
    system("cls");
    string s = "the sky is blue";
    reverserTheWordsOfString( s );
    cout<<s<<endl;
    return 0;
}