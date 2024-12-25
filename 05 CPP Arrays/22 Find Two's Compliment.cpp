#include <iostream>
#include <vector>

using namespace std;

void printArray(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
};
void onesCompliment(vector<int> &arr, vector<int> &ans)
{
    cout << "Calculating ones compliment..." << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        ans[i + 1] = arr[i] == 1 ? 0 : 1;
    }
    cout << "Calculated ones compliment." << endl;
};
void twosCompliment(vector<int> &arr)
{
    int carry = 1;

    for (int i = arr.size() - 1; i > 0; i--)
    {
        int digit = arr[i] + carry;
        arr[i] = digit % 2;
        carry = digit / 2;
    }

    if (carry)
    {
        arr[0] = carry;
    }
};

int main()
{
    vector<int> arr = {1, 1, 0, 0};
    printArray(arr);
    vector<int> twosComp(arr.size() + 1, 0);
    onesCompliment(arr, twosComp);
    printArray(twosComp);
    twosCompliment(twosComp);
    printArray(twosComp);
    return 0;
}