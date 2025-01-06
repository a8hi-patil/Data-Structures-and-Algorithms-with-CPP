#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    system("cls");
    int a[] = {1, 2, 3, 4};

    // this line will print 1 and 2
    cout << *a << " " << *(a + 1) << endl;
    int b[] = {1, 2, 3};

    // this line will print 1 and 3
    cout << *b << " " << *(b + 2) << endl;
    int c[] = {1, 2, 3, 4};

    int *p = c++;
    // this line will throw error
    cout << *p << " " << endl;
    return 0;
}