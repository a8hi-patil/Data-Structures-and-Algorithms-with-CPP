#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

int compress(vector<char> &chars)
{
    int len = chars.size();
    if (len == 0 || len == 1)
    {
        return len;
    }

    int i = 0;
    char prev = chars[i];
    int counter = 0;
    int newLen = 0;
    int arrayPointer = 0;
    while (i < len)
    {
        char curr = chars[i];
        if (curr == prev)
        {
            counter++;
            prev = curr;
        }
        else
        {
            if (counter == 1)
            {
                chars[arrayPointer] = prev;
                arrayPointer++;
                newLen++;
            }
            else
            {
                chars[arrayPointer] = prev;
                arrayPointer++;
                newLen++;
                string tempC = to_string(counter);

                for (int i = 0; i < tempC.length(); i++)
                {
                    chars[arrayPointer] = tempC[i];
                    arrayPointer++;
                    newLen++;
                }
            }
            counter = 1;
            prev = curr;
        }
        i++;
    }
    if (counter == 1)
    {
        chars[arrayPointer] = prev;
        arrayPointer++;
        newLen++;
    }
    else
    {
        chars[arrayPointer] = prev;
        arrayPointer++;
        newLen++;
        string tempC = to_string(counter);

        for (int i = 0; i < tempC.length(); i++)
        {
            chars[arrayPointer] = tempC[i];
            arrayPointer++;
            newLen++;
        }
    }
    return newLen;
}
int main()
{
    system("cls");
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    chars = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
    chars = {'a', 'b'};
    chars = {
        'a',
    };
    int x = compress(chars);
    for (int i = 0; i < x; i++)
    {
        cout << chars[i] << ", ";
    }

    return 0;
}