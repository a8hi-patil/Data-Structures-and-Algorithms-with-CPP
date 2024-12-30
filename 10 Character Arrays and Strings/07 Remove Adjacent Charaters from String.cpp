#include <iostream>
#include <cstdlib>
using namespace std;

string removeDuplicateAdjacentCharacters(string str)
{
    string st;
    for (int i = 0; i < str.size(); i++)
    {
        if (st.empty())
        {
            st.push_back(str[i]);
        }
        else
        {
            if (st.back() == str[i])
            {
                st.pop_back();
                continue;
            }
            st.push_back(str[i]);
        }
    }
    return st;
}

int main()
{
    system("cls");
    string str = "abbaca";
    string ans = removeDuplicateAdjacentCharacters(str);
    cout << "Ans string is " << ans << endl;
    return 0;
}