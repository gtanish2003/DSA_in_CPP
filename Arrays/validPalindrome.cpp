#include <iostream>
#include <string>
using namespace std;
/** Question Statement:  Faltu characters ko remove krn ah and fir sbko lowercase me convert
 * krna h and fir palindrome check krna h */

bool valid(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
        return 1;
    else
        return 0;
}

char toLowerCase(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
        return ch;
    else
        return ch - 'A' + 'a';
}

bool isPalindrome(string a)
{
    string temp = "";
    for (int i = 0; i < a.length(); i++)
    {
        if (valid(a[i]))
        {
            temp.push_back(a[i]);
        }
    }

    for (int i = 0; i < temp.length(); i++)
    {
        temp[i] = toLowerCase(temp[i]);
    }

    int s = 0;
    int e = temp.length() - 1;
    while (s <= e)
    {
        if (temp[s] != temp[e])
            return 0;

        else
        {
            s++;
            e--;
        }
    }
    return 1;
}

int main()
{
    string str;
    cout << "Enter the input string" << endl;
    getline(cin, str);

    cout << isPalindrome(str);
}