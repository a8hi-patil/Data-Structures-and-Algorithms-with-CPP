#include<iostream>
#include<bits/stdc++.h>
using namespace std;
static string orderCopy;

bool cmp( char a, char b){
        return ( orderCopy.find(a) < orderCopy.find(b));
}

string customeSort( string order , string s){
    sort( s.begin(),s.end(),cmp);
    return s;
}
  
int main()
{
   string order = "cba", s = "abcd";
   orderCopy = order;
   cout<<customeSort(order,s);
    return 0;
}