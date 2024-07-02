#include<iostream>
using namespace std;

int createNumber( int size){
    int num = 0 ; int digit;
    while (size)
    {
        cout<<"Enter digit : ";
        cin>>digit;
        num = num * 10 + digit;
        size--;
    }
    return num;
}

int main () {
    int n ;
    cout<<"Enter the size of number : ";
    cin >> n;
    int res = createNumber( n );
    cout<<"Created number is "<<res;
    return 0;
}