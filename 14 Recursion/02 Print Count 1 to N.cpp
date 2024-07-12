#include<iostream>
#include <cstdlib>
using namespace std;
void printNumbersUptoN( int n ){
    if(  n == 0){
        return;
    }
    printNumbersUptoN( n - 1);
    cout<<n<<" ";

}
int main()
{
    system("cls");
    int n = 10;
    printNumbersUptoN( n );
    return 0;
}