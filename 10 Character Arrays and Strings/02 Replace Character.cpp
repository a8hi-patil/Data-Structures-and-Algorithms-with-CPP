#include <iostream>
#include <cstdlib>
using namespace std;
void changeCharacter(char ar[], char org, char rlpc)
{
    int idx = 0;
    while (ar[idx] != '\0')
    {
        if (ar[idx] == org)
            ar[idx] = rlpc;
        idx++;
    }
}
int main()
{
    system("cls");
    char name[] = {'a', 'b', 'h', 'i', '\0'};
    cout << name << endl;
    changeCharacter(name, 'a', 'A');
    cout << name << endl;
    return 0;
}