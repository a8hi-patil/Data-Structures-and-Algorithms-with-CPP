#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    // system("cls");
    int n = 15;

    for (int i = 0; i < n; i++)
    {
        int end = i <= n / 2 ? 2 * i : 2 * (n - i - 1);

        for (int j = 0; j < end + 1; j++)
        {
            if (j <= end / 2)
            {
                cout << j++;
            }
            else
            {

                cout << end - j + 1;
            }
        }
        cout << endl;
    }

    return 0;
}