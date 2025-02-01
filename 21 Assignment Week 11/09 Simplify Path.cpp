#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <stack>
using namespace std;
void buildAns(stack<string> st, string &ans)
{
    if (st.empty())
    {
        return;
    }
    string top = st.top();
    st.pop();
    buildAns(st, ans);
    ans += top;
}
string simplifyPath(string path)
{
    stack<string> st;
    int i = 0;
    while (i < path.length())
    {
        int end = i + 1;

        while (path[end] != '/' && end < path.length())
        {
            end++;
        }
        string tempPath = path.substr(i, end - i);
        i = end;
        end = i + 1;
        if (tempPath == "/" || tempPath == "/.")
        {
            continue;
        }
        if (tempPath == "/..")
        {
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            st.push(tempPath);
        }
    }
    string ans = st.empty() ? "/" : "";
    buildAns(st, ans);
    return ans;
}

void test(string &ip, string &op, int num)
{
    string ans = simplifyPath(ip);
    bool flag = true;
    if (ans == op)
    {
        flag = true;
    }
    else
    {
        flag = false;
    }
    string msg = flag ? "Passed " : "Failed ";

    cout << "Test Case " << num + 1 << " " << msg << " : "
         << "Expected : "
         << op
         << " Output : "
         << ans
         << endl;
}
int main()
{
    system("cls");
    vector<string> inp = {"/home/", "/home//foo/", "/home/user/Documents/../Pictures", "/../", "/.../a/../b/c/../d/./"};
    vector<string> op = {"/home", "/home/foo", "/home/user/Pictures", "/", "/.../b/d"};

    for (int i = 0; i < inp.size(); i++)
    {
        test(inp[i], op[i], i);
    }

    return 0;
}