#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
void printCommon(vector<int> A, vector<int> B, vector<int> C)
{
    int m, n, o;
    m = A.size() - 1;
    n = B.size() - 1;
    o = C.size() - 1;
    int i = 0, j = 0, k = 0;

    while (i <= m && j <= n && k <= o)
    {
        if (A[i] == B[j] && B[j] == C[k])
        {
            cout << A[i] << ",";
            i++;
            j++;
            k++;
        }
        else if (A[i] < B[j])
        {
            i++;
        }
        else if (B[j] < C[k])
        {
            j++;
        }
        else
        {
            k++;
        }
    }
}
int main()
{
    system("cls");
    vector<int> A = {1, 5, 10, 20, 40, 80},
                B = {6, 7, 20, 80, 100},
                C = {3, 4, 15, 20, 30, 70, 80, 120};
    printCommon(A, B, C);
    return 0;
}