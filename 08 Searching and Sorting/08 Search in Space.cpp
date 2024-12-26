#include <iostream>
#include <cstdlib>
using namespace std;
int searchInSpace(int dvdnt, int dvsr)
{
    int start = dvsr;
    int end = dvdnt;
    int mid = start + (end - start) / 2;
    int ans = -1;
    while (start <= end)
    {
        if (mid * dvsr == dvdnt)
        {
            return mid;
        }
        else if (mid * dvsr > dvdnt)
        {
            end = mid - 1;
        }
        else
        {
            ans = mid;
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}
int main()
{
    system("cls");
    cout << "9 / 3 = " << searchInSpace(9, 3) << endl;
    return 0;
}