#include <iostream>
#include <cstdlib>
using namespace std;
int findLengthOfCharArray(char arr[])
{
    int len = 0;

    while (arr[len] != '\0')
    {
        len++;
    }
    return len;
}
int main()
{
    system("cls");
    char name[] = {'a', 'b', 'h', 'i', '\0'};
    cout << "Size of character array is " << findLengthOfCharArray(name) << endl;
    return 0;
}