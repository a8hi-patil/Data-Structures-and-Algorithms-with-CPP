#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int main()
{
    system("cls");
    // declaration and initilisation

    vector<int> a;
    vector<int> b = {1, 2, 3, 4};
    vector<int> c(4, 7);
    vector<int> d(b);

    b.begin();
    b.end();
    b.push_back(1);
    b.pop_back();
    b.at(3);
    b.capacity();
    b.size();
    b.max_size();
    b.clear();

    return 0;
}