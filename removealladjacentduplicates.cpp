#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cout << "Enter the input string:" << endl;
    getline(cin, str);
    // first removal of the adjacent duplicates elements

    int j = 0;
    while (j < str.length())
    {

        for (int i = 0; i < str.length(); i++)
        {
            if ((str[i] == str[i + 1]))
            {
                str.erase(str.begin() + i, str.begin() + i + 2);
            }
        }
        j++;
    }
    cout << str;
}
