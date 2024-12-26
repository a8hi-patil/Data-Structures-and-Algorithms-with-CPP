#include <iostream>
#include <unordered_map>
#include <cstdlib>
using namespace std;
int main()
{
    system("cls");
    unordered_map<string, string> table;
    table["in"] = "India";
    table.insert(make_pair("en", "England"));

    table.size();
    table.empty();
    table.begin();
    table.find("d");
    table.clear();
    table.end();
    return 0;
}