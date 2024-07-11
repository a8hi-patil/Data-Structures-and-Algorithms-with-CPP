#include<iostream>
#include<vector>
using namespace std;
void changeCharacter( char arr[],char originalCharacter, char updatedCharacter){
    int idx = 0;
    while(arr[idx] != '\n'){
        if(arr[idx] == originalCharacter){
            arr[idx] = updatedCharacter;
        }
        idx++;
    }
}

int main()
{
    char name[]={'a','b','h','i'};
    int size = 4;
    changeCharacter(name,'a','A');
    cout<<name<<endl;
    return 0;
}