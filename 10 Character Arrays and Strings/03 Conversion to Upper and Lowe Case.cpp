#include <iostream>
#include <cstdlib>
using namespace std;
void loweToUpperCase(char arr[])
{
    int idx = 0;
    while (arr[idx] != '\0')
    {
        arr[idx] = arr[idx] - 'a' + 'A';
        idx++;
    }
}
void upperToLowerCase(char arr[])
{
    int idx = 0;
    while (arr[idx] != '\0')
    {
        arr[idx] = 'a' - 'A' + arr[idx];
        idx++;
    }
}
int main()
{
    system("cls");
    char name[] = {'a', 'b', 'h', 'i', '\0'};
    loweToUpperCase(name);
    cout << name << endl;
    upperToLowerCase(name);
    cout << name << endl;
    return 0;
}