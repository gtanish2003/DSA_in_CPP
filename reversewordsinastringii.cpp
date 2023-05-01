#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string str;
    cout << "Enter the input string:" << endl;
    getline(cin, str);
    int l = 0;
    int r = 0;
    while (l < str.length())
    {
        while (r < str.length() && str[r] != ' ')
        {
            r++;
        }

        reverse(str.begin() + l, str.begin() + r);
        l = r + 1;
        r = l;
    }

    cout << "The string after reversing words is :" << endl;
    cout << str;
}