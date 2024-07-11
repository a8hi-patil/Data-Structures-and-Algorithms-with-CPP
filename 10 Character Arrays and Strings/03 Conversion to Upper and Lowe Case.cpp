#include<iostream>
#include<vector>
using namespace std;
void loweToUpperCase(char arr[]){
    int idx = 0;
    while(arr[idx] != '\0'){
        int upperCase = arr[idx]-'a'+'A';
        arr[idx] = char(upperCase);
        idx++;
    }
}
void upperToLowerCase(char arr[]){
    int idx = 0;
    while(arr[idx] != '\0'){
        int upperCase = arr[idx]-'A'+'a';
        arr[idx] = char(upperCase);
        idx++;
    }
}
int main()
{
    char name[]={'a','b','h','i'};
    int size = 4;
    loweToUpperCase(name);
    cout<<name<<endl;
    upperToLowerCase(name);
    cout<<name<<endl;
    return 0;
}