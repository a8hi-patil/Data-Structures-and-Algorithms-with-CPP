#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    system("cls");
    char st[] = "ABCD";

    for (int i = 0; st[i] != '\0'; i++)
    {
        // this line will print A 65 A A
        // this line will print B 66 B B
        // this line will print C 67 C C
        cout << st[i] << " " << *(st) + i << " " << *(i + st) << " " << i[st] << endl;
    }

    return 0;
}